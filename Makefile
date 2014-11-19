all: libReQL.a

libReQL.a: ReQL-CPP.o ReQL-ast-CPP.o ReQL-expr-CPP.o ReQL.o ReQL-ast.o ReQL-expr.o
	g++ -shared -o libReQL.a \
            ReQL-CPP.o \
            ReQL-ast-CPP.o \
            ReQL-expr-CPP.o \
            ReQL.o \
            ReQL-ast.o \
            ReQL-expr.o

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
