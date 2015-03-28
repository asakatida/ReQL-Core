all: libReQL.a

test: libReQLtest
	./libReQLtest

clean:
	rm -f *.o *.obj *.a libReQLtest

OBJS = ReQL.obj \
	ReQL-ast.obj \
	ReQL-expr.obj \
	ReQL-new.obj \
	ReQL-decode.o \
	ReQL-encode.o \
	ReQL.o \
	ReQL-ast.o \
	ReQL-char.o \
	ReQL-cursor.o \
	ReQL-expr.o \
	ReQL-json.o
TESTOBJS = ReQL-test.obj \
	ReQL-ast-test.o \
	ReQL-decode-test.o \
	ReQL-encode-test.o \
	ReQL-expr-test.o \
	ReQL-expr-test.obj

LDFLAGS += -pthread -std=c++11
CXXFLAGS += -fPIC -std=c++11 -Wall -Wextra -Werror -pedantic -pedantic-errors \
	-Isrc
CCFLAGS += -fPIC -std=c11 -Wall -Wextra -Werror -pedantic -pedantic-errors \
	-Isrc

ReQL.obj:
	$(CXX) $(CXXFLAGS) -o ReQL.obj -c src/ReQL.cpp

ReQL-ast.obj:
	$(CXX) $(CXXFLAGS) -o ReQL-ast.obj -c src/cpp/ast.cpp

ReQL-expr.obj:
	$(CXX) $(CXXFLAGS) -o ReQL-expr.obj -c src/cpp/expr.cpp

ReQL-new.obj:
	$(CXX) $(CXXFLAGS) -o ReQL-new.obj -c src/cpp/new.cpp

ReQL-decode.o:
	$(CC) $(CCFLAGS) -o ReQL-decode.o -c src/c/decode.c

ReQL-encode.o:
	$(CC) $(CCFLAGS) -o ReQL-encode.o -c src/c/encode.c

ReQL.o:
	$(CC) $(CCFLAGS) -o ReQL.o -c src/ReQL.c

ReQL-ast.o:
	$(CC) $(CCFLAGS) -o ReQL-ast.o -c src/c/ast.c

ReQL-char.o:
	$(CC) $(CCFLAGS) -o ReQL-char.o -c src/c/char.c

ReQL-cursor.o:
	$(CC) $(CCFLAGS) -o ReQL-cursor.o -c src/c/cursor.c

ReQL-expr.o:
	$(CC) $(CCFLAGS) -o ReQL-expr.o -c src/c/expr.c

ReQL-json.o:
	$(CC) $(CCFLAGS) -o ReQL-json.o -c src/c/json.c

ReQL-test.obj:
	$(CXX) $(CXXFLAGS) -o ReQL-test.obj -c test/test.cpp

ReQL-ast-test.o:
	$(CXX) $(CXXFLAGS) -o ReQL-ast-test.o -c test/c/ast.cpp

ReQL-decode-test.o:
	$(CXX) $(CXXFLAGS) -o ReQL-decode-test.o -c test/c/decode.cpp

ReQL-encode-test.o:
	$(CXX) $(CXXFLAGS) -o ReQL-encode-test.o -c test/c/encode.cpp

ReQL-expr-test.o:
	$(CXX) $(CXXFLAGS) -o ReQL-expr-test.o -c test/c/expr.cpp

ReQL-expr-test.obj:
	$(CXX) $(CXXFLAGS) -o ReQL-expr-test.obj -c test/cpp/expr.cpp

libReQL.a: $(OBJS)
	$(CXX) $(LDFLAGS) -shared -o $@ $(OBJS)

libReQLtest: $(OBJS) $(TESTOBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(TESTOBJS)
