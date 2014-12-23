all: libReQL.a

test: libReQLtest
	./libReQLtest

libReQL.a: ReQL-CPP.o ReQL-ast-CPP.o ReQL-expr-CPP.o ReQL.o ReQL-ast.o ReQL-expr.o ReQL-json.o
	g++ -shared -o libReQL.a \
            ReQL-CPP.o \
            ReQL-ast-CPP.o \
            ReQL-expr-CPP.o \
            ReQL.o \
            ReQL-ast.o \
            ReQL-expr.o \
            ReQL-json.o

ReQL-CPP.o: ReQL-CPP.cpp
	gcc -fPIC -c $<

ReQL-ast-CPP.o: ReQL-ast-CPP.cpp
	gcc -fPIC -c $<

ReQL-expr-CPP.o: ReQL-expr-CPP.cpp
	gcc -fPIC -c $<

ReQL.o: ReQL.c
	gcc -fPIC -c $<

ReQL-ast.o: ReQL-ast.c
	gcc -fPIC -c $<

ReQL-expr.o: ReQL-expr.c
	gcc -fPIC -c $<

ReQL-json.o: ReQL-json.c
	gcc -fPIC -c $<

libReQLtest: all ReQL-test.o ReQL-ast-test.o ReQL-expr-test.o
	g++ -o libReQLtest \
            ReQL-test.o \
            ReQL-ast-test.o \
            ReQL-expr-test.o \
            libReQL.a

ReQL-test.o: ReQL-test.cpp
	g++ -fPIC -c $<

ReQL-ast-test.o: ReQL-ast-test.cpp
	g++ -fPIC -c $<

ReQL-expr-test.o: ReQL-expr-test.cpp
	g++ -fPIC -c $<
