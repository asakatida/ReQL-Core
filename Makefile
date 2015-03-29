all: libReQL.a

test: libReQLtest
	./libReQLtest

clean:
	rm -f *.o *.obj *.a libReQLtest

OBJS = \
	ReQL-ast.o \
	ReQL-ast.obj \
	ReQL-char.o \
	ReQL-connection.o \
	ReQL-connection.obj \
	ReQL-cursor.o \
	ReQL-decode.o \
	ReQL-encode.o \
	ReQL-error.o \
	ReQL-expr.o \
	ReQL-expr.obj \
	ReQL-json.o \
	ReQL-new.obj \
	ReQL.o \
	ReQL.obj

TESTOBJS = ReQL-test.obj \
	ReQL-ast-test.o \
	ReQL-decode-test.o \
	ReQL-encode-test.o \
	ReQL-expr-test.o \
	ReQL-expr-test.obj

LDFLAGS += -pthread -std=c++11

CXXFLAGS += -fPIC -std=c++11 -Wall -Wextra -Werror -pedantic -pedantic-errors -Isrc

CCFLAGS += -fPIC -std=c11 -Wall -Wextra -Werror -pedantic -pedantic-errors -Isrc

ReQL.obj:
	$(CXX) $(CXXFLAGS) -o $@ -c src/ReQL.cpp

ReQL-ast.obj:
	$(CXX) $(CXXFLAGS) -o $@ -c src/cpp/ast.cpp

ReQL-expr.obj:
	$(CXX) $(CXXFLAGS) -o $@ -c src/cpp/expr.cpp

ReQL-new.obj:
	$(CXX) $(CXXFLAGS) -o $@ -c src/cpp/new.cpp

ReQL-decode.o:
	$(CC) $(CCFLAGS) -o $@ -c src/c/decode.c

ReQL-encode.o:
	$(CC) $(CCFLAGS) -o $@ -c src/c/encode.c

ReQL.o:
	$(CC) $(CCFLAGS) -o $@ -c src/ReQL.c

ReQL-ast.o:
	$(CC) $(CCFLAGS) -o $@ -c src/c/ast.c

ReQL-char.o:
	$(CC) $(CCFLAGS) -o $@ -c src/c/char.c

ReQL-cursor.o:
	$(CC) $(CCFLAGS) -o $@ -c src/c/cursor.c

ReQL-expr.o:
	$(CC) $(CCFLAGS) -o $@ -c src/c/expr.c

ReQL-json.o:
	$(CC) $(CCFLAGS) -o $@ -c src/c/json.c

ReQL-test.obj:
	$(CXX) $(CXXFLAGS) -Itest -o $@ -c test/test.cpp

ReQL-ast-test.o:
	$(CXX) $(CXXFLAGS) -Itest -o $@ -c test/c/ast.cpp

ReQL-decode-test.o:
	$(CXX) $(CXXFLAGS) -Itest -o $@ -c test/c/decode.cpp

ReQL-encode-test.o:
	$(CXX) $(CXXFLAGS) -Itest -o $@ -c test/c/encode.cpp

ReQL-expr-test.o:
	$(CXX) $(CXXFLAGS) -Itest -o $@ -c test/c/expr.cpp

ReQL-expr-test.obj:
	$(CXX) $(CXXFLAGS) -Itest -o $@ -c test/cpp/expr.cpp

libReQL.a: $(OBJS)
	$(CXX) $(LDFLAGS) -shared -o $@ $(OBJS)

libReQLtest: $(OBJS) $(TESTOBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(TESTOBJS)
