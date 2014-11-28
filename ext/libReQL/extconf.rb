require 'mkmf'

## monkey patched create_makefile by Adam Grandquist

##
# mkmf.rb is used by ruby C extensions to generate a Makefile which will
# correctly compile and link the C extension to ruby and a third-party
# library.
module MakeMakefile
  CONFTEST = "conftest".freeze

  # Generates the Makefile for your extension, passing along any options and
  # preprocessor constants that you may have generated through other methods.
  #
  # The +target+ name should correspond the name of the global function name
  # defined within your C extension, minus the +Init_+.  For example, if your
  # C extension is defined as +Init_foo+, then your target would simply be
  # "foo".
  #
  # If any "/" characters are present in the target name, only the last name
  # is interpreted as the target name, and the rest are considered toplevel
  # directory names, and the generated Makefile will be altered accordingly to
  # follow that directory structure.
  #
  # For example, if you pass "test/foo" as a target name, your extension will
  # be installed under the "test" directory.  This means that in order to
  # load the file within a Ruby program later, that directory structure will
  # have to be followed, e.g. <code>require 'test/foo'</code>.
  #
  # The +srcprefix+ should be used when your source files are not in the same
  # directory as your build script. This will not only eliminate the need for
  # you to manually copy the source files into the same directory as your
  # build script, but it also sets the proper +target_prefix+ in the generated
  # Makefile.
  #
  # Setting the +target_prefix+ will, in turn, install the generated binary in
  # a directory under your <code>RbConfig::CONFIG['sitearchdir']</code> that
  # mimics your local filesystem when you run <code>make install</code>.
  #
  # For example, given the following file tree:
  #
  #   ext/
  #     extconf.rb
  #     test/
  #       foo.c
  #
  # And given the following code:
  #
  #   create_makefile('test/foo', 'test')
  #
  # That will set the +target_prefix+ in the generated Makefile to "test".
  # That, in turn, will create the following file tree when installed via the
  # <code>make install</code> command:
  #
  #   /path/to/ruby/sitearchdir/test/foo.so
  #
  # It is recommended that you use this approach to generate your makefiles,
  # instead of copying files around manually, because some third party
  # libraries may depend on the +target_prefix+ being set properly.
  #
  # The +srcprefix+ argument can be used to override the default source
  # directory, i.e. the current directory.  It is included as part of the
  # +VPATH+ and added to the list of +INCFLAGS+.
  #
  def create_makefile(target, srcprefix = nil)
    $target = target
    libpath = $DEFLIBPATH|$LIBPATH
    message "creating Makefile\n"
    MakeMakefile.rm_f "conftest*"
    if CONFIG["DLEXT"] == $OBJEXT
      for lib in libs = $libs.split
        lib.sub!(/-l(.*)/, %%"lib\\1.#{$LIBEXT}"%)
      end
      $defs.push(format("-DEXTLIB='%s'", libs.join(",")))
    end

    if target.include?('/')
      target_prefix, target = File.split(target)
      target_prefix[0,0] = '/'
    else
      target_prefix = ""
    end

    srcprefix ||= "$(srcdir)/#{srcprefix}".chomp('/')
    RbConfig.expand(srcdir = srcprefix.dup)

    ext = ".#{$OBJEXT}"
    orig_srcs = [
      'ReQL-ast-Ruby.c',
      'ReQL-ast.c',
      'ReQL-expr-Ruby.c',
      'ReQL-expr.c',
      'ReQL-Ruby.c',
      'ReQL.c'
    ] ## Monkey patch
    if not $objs
      srcs = $srcs || orig_srcs
      objs = srcs.inject(Hash.new {[]}) {|h, f| h[File.basename(f, ".*") << ext] <<= f; h}
      $objs = objs.keys
      unless objs.delete_if {|b, f| f.size == 1}.empty?
        dups = objs.sort.map {|b, f|
          "#{b[/.*\./]}{#{f.collect {|n| n[/([^.]+)\z/]}.join(',')}}"
        }
        abort "source files duplication - #{dups.join(", ")}"
      end
    else
      $objs.collect! {|o| File.basename(o, ".*") << ext} unless $OBJEXT == "o"
      srcs = $srcs || $objs.collect {|o| o.chomp(ext) << ".c"}
    end
    $srcs = srcs

    hdrs = Dir[File.join(srcdir, "*.{#{HDR_EXT.join(%q{,})}}")]

    target = nil if $objs.empty?

    if target and EXPORT_PREFIX
      if File.exist?(File.join(srcdir, target + '.def'))
        deffile = "$(srcdir)/$(TARGET).def"
        unless EXPORT_PREFIX.empty?
          makedef = %{-pe "$_.sub!(/^(?=\\w)/,'#{EXPORT_PREFIX}') unless 1../^EXPORTS$/i"}
        end
      else
        makedef = %{-e "puts 'EXPORTS', '$(TARGET_ENTRY)'"}
      end
      if makedef
        $cleanfiles << '$(DEFFILE)'
        origdef = deffile
        deffile = "$(TARGET)-$(arch).def"
      end
    end
    origdef ||= ''

    if $extout and $INSTALLFILES
      $cleanfiles.concat($INSTALLFILES.collect {|files, dir|File.join(dir, files.sub(/\A\.\//, ''))})
      $distcleandirs.concat($INSTALLFILES.collect {|files, dir| dir})
    end

    if $extmk and not $extconf_h
      create_header
    end

    libpath = libpathflag(libpath)

    dllib = target ? "$(TARGET).#{CONFIG['DLEXT']}" : ""
    staticlib = target ? "$(TARGET).#$LIBEXT" : ""
    mfile = open("Makefile", "wb")
    conf = configuration(srcprefix)
    conf = yield(conf) if block_given?
    mfile.puts(conf)
    mfile.print "
libpath = #{($DEFLIBPATH|$LIBPATH).join(" ")}
LIBPATH = #{libpath}
DEFFILE = #{deffile}

CLEANFILES = #{$cleanfiles.join(' ')}
DISTCLEANFILES = #{$distcleanfiles.join(' ')}
DISTCLEANDIRS = #{$distcleandirs.join(' ')}

extout = #{$extout && $extout.quote}
extout_prefix = #{$extout_prefix}
target_prefix = #{target_prefix}
LOCAL_LIBS = #{$LOCAL_LIBS}
LIBS = #{$LIBRUBYARG} #{$libs} #{$LIBS}
ORIG_SRCS = #{orig_srcs.collect(&File.method(:basename)).join(' ')}
SRCS = $(ORIG_SRCS) #{(srcs - orig_srcs).collect(&File.method(:basename)).join(' ')}
OBJS = #{$objs.join(" ")}
HDRS = #{hdrs.map{|h| '$(srcdir)/' + File.basename(h)}.join(' ')}
TARGET = #{target}
TARGET_NAME = #{target && target[/\A\w+/]}
TARGET_ENTRY = #{EXPORT_PREFIX || ''}Init_$(TARGET_NAME)
DLLIB = #{dllib}
EXTSTATIC = #{$static || ""}
STATIC_LIB = #{staticlib unless $static.nil?}
#{!$extout && defined?($installed_list) ? "INSTALLED_LIST = #{$installed_list}\n" : ""}
" #"
    # TODO: fixme
    install_dirs.each {|d| mfile.print("%-14s= %s\n" % d) if /^[[:upper:]]/ =~ d[0]}
    n = ($extout ? '$(RUBYARCHDIR)/' : '') + '$(TARGET)'
    mfile.print "
TARGET_SO     = #{($extout ? '$(RUBYARCHDIR)/' : '')}$(DLLIB)
CLEANLIBS     = #{n}.#{CONFIG['DLEXT']} #{config_string('cleanlibs') {|t| t.gsub(/\$\*/) {n}}}
CLEANOBJS     = *.#{$OBJEXT} #{config_string('cleanobjs') {|t| t.gsub(/\$\*/, "$(TARGET)#{deffile ? '-$(arch)': ''}")} if target} *.bak

all:    #{$extout ? "install" : target ? "$(DLLIB)" : "Makefile"}
static: $(STATIC_LIB)#{$extout ? " install-rb" : ""}
.PHONY: all install static install-so install-rb
.PHONY: clean clean-so clean-static clean-rb
"
    mfile.print CLEANINGS
    fsep = config_string('BUILD_FILE_SEPARATOR') {|s| s unless s == "/"}
    if fsep
      sep = ":/=#{fsep}"
      fseprepl = proc {|s|
        s = s.gsub("/", fsep)
        s = s.gsub(/(\$\(\w+)(\))/) {$1+sep+$2}
        s = s.gsub(/(\$\{\w+)(\})/) {$1+sep+$2}
      }
      rsep = ":#{fsep}=/"
    else
      fseprepl = proc {|s| s}
      sep = ""
      rsep = ""
    end
    dirs = []
    mfile.print "install: install-so install-rb\n\n"
    sodir = (dir = "$(RUBYARCHDIR)").dup
    mfile.print("install-so: ")
    if target
      f = "$(DLLIB)"
      dest = "#{dir}/#{f}"
      if $extout
        mfile.puts dest
        mfile.print "clean-so::\n"
        mfile.print "\t-$(Q)$(RM) #{fseprepl[dest]}\n"
        mfile.print "\t-$(Q)$(RMDIRS) #{fseprepl[dir]}#{$ignore_error}\n"
      else
        mfile.print "#{f} #{timestamp_file(dir)}\n"
        mfile.print "\t$(INSTALL_PROG) #{fseprepl[f]} #{dir}\n"
        if defined?($installed_list)
          mfile.print "\t@echo #{dir}/#{File.basename(f)}>>$(INSTALLED_LIST)\n"
        end
      end
      mfile.print "clean-static::\n"
      mfile.print "\t-$(Q)$(RM) $(STATIC_LIB)\n"
    else
      mfile.puts "Makefile"
    end
    mfile.print("install-rb: pre-install-rb install-rb-default\n")
    mfile.print("install-rb-default: pre-install-rb-default\n")
    mfile.print("pre-install-rb: Makefile\n")
    mfile.print("pre-install-rb-default: Makefile\n")
    for sfx, i in [["-default", [["lib/**/*.rb", "$(RUBYLIBDIR)", "lib"]]], ["", $INSTALLFILES]]
      files = install_files(mfile, i, nil, srcprefix) or next
      for dir, *files in files
        unless dirs.include?(dir)
          dirs << dir
          mfile.print "pre-install-rb#{sfx}: #{timestamp_file(dir)}\n"
        end
        for f in files
          dest = "#{dir}/#{File.basename(f)}"
          mfile.print("install-rb#{sfx}: #{dest}\n")
          mfile.print("#{dest}: #{f} #{timestamp_file(dir)}\n")
          mfile.print("\t$(Q) $(#{$extout ? 'COPY' : 'INSTALL_DATA'}) #{f} $(@D#{sep})\n")
          if defined?($installed_list) and !$extout
            mfile.print("\t@echo #{dest}>>$(INSTALLED_LIST)\n")
          end
          if $extout
            mfile.print("clean-rb#{sfx}::\n")
            mfile.print("\t-$(Q)$(RM) #{fseprepl[dest]}\n")
          end
        end
      end
      mfile.print "pre-install-rb#{sfx}:\n"
      mfile.print("\t$(ECHO) installing#{sfx.sub(/^-/, " ")} #{target} libraries\n")
      if $extout
        dirs.uniq!
        unless dirs.empty?
          mfile.print("clean-rb#{sfx}::\n")
          for dir in dirs.sort_by {|d| -d.count('/')}
            mfile.print("\t-$(Q)$(RMDIRS) #{fseprepl[dir]}#{$ignore_error}\n")
          end
        end
      end
    end
    dirs.unshift(sodir) if target and !dirs.include?(sodir)
    dirs.each do |d|
      t = timestamp_file(d)
      mfile.print "#{t}:\n\t$(Q) $(MAKEDIRS) #{d}\n\t$(Q) $(TOUCH) $@\n"
    end

    mfile.print <<-SITEINSTALL

site-install: site-install-so site-install-rb
site-install-so: install-so
site-install-rb: install-rb

    SITEINSTALL

    return unless target

    mfile.puts SRC_EXT.collect {|e| ".path.#{e} = $(VPATH)"} if $nmake == ?b
    mfile.print ".SUFFIXES: .#{SRC_EXT.join(' .')} .#{$OBJEXT}\n"
    mfile.print "\n"

    compile_command = "\n\t$(ECHO) compiling $(<#{rsep})\n\t$(Q) %s\n\n"
    CXX_EXT.each do |e|
      each_compile_rules do |rule|
        mfile.printf(rule, e, $OBJEXT)
        mfile.printf(compile_command, COMPILE_CXX)
      end
    end
    C_EXT.each do |e|
      each_compile_rules do |rule|
        mfile.printf(rule, e, $OBJEXT)
        mfile.printf(compile_command, COMPILE_C)
      end
    end

    mfile.print "$(RUBYARCHDIR)/" if $extout
    mfile.print "$(DLLIB): "
    mfile.print "$(DEFFILE) " if makedef
    mfile.print "$(OBJS) Makefile"
    mfile.print " #{timestamp_file('$(RUBYARCHDIR)')}" if $extout
    mfile.print "\n"
    mfile.print "\t$(ECHO) linking shared-object #{target_prefix.sub(/\A\/(.*)/, '\1/')}$(DLLIB)\n"
    mfile.print "\t-$(Q)$(RM) $(@#{sep})\n"
    link_so = LINK_SO.gsub(/^/, "\t$(Q) ")
    if srcs.any?(&%r"\.(?:#{CXX_EXT.join('|')})\z".method(:===))
      link_so = link_so.sub(/\bLDSHARED\b/, '\&XX')
    end
    mfile.print link_so, "\n\n"
    unless $static.nil?
      mfile.print "$(STATIC_LIB): $(OBJS)\n\t-$(Q)$(RM) $(@#{sep})\n\t"
      mfile.print "$(ECHO) linking static-library $(@#{rsep})\n\t$(Q) "
      mfile.print "$(AR) #{config_string('ARFLAGS') || 'cru '}$@ $(OBJS)"
      config_string('RANLIB') do |ranlib|
        mfile.print "\n\t-$(Q)#{ranlib} $(DLLIB) 2> /dev/null || true"
      end
    end
    mfile.print "\n\n"
    if makedef
      mfile.print "$(DEFFILE): #{origdef}\n"
      mfile.print "\t$(ECHO) generating $(@#{rsep})\n"
      mfile.print "\t$(Q) $(RUBY) #{makedef} #{origdef} > $@\n\n"
    end

    depend = File.join(srcdir, "depend")
    if File.exist?(depend)
      mfile.print("###\n", *depend_rules(File.read(depend)))
    else
      mfile.print "$(OBJS): $(HDRS) $(ruby_headers)\n"
    end

    $makefile_created = true
  ensure
    mfile.close if mfile
  end
end

create_makefile 'libReQL', '../../../../'
