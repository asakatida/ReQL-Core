require 'rake/extensiontask'
require 'rubygems/package_task'

Rake::ExtensionTask.new 'libReQL' do |ext|
  ext.lib_dir = 'lib'
end

spec = Gem::Specification.new do |s|
  s.author = 'Adam Grandquist'
  s.authors = ['Adam Grandquist']
  s.description = <<-EOF
A Ruby driver for RethinkDB.
  EOF
  s.files = [
    'ReQL-ast-Ruby.c',
    'ReQL-ast.c',
    'ReQL-expr-Ruby.c',
    'ReQL-expr.c',
    'ReQL-Ruby.c',
    'ReQL.c'
  ]
  s.email = 'grandquista@gmail.com'
  s.extensions << 'extconf.rb'
  s.homepage = 'https://github.com/grandquista/ReQL-Core/wiki'
  s.licenses = ['Apache']
  s.name = 'libReQL'
  s.platform = Gem::Platform::RUBY
  s.require_paths = ['.']
  s.summary = 'A Ruby driver for RethinkDB.'
  s.version = '0.1.0'
end

Gem::PackageTask.new(spec) do |pkg|
  pkg.need_zip = true
  pkg.need_tar = true
end

task test: %w[compile] do
end

task default: :test
