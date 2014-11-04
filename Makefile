all: build

build:
	gcc -c \
            ReQL-expr.c \
            ReQL-ast.c \
            ReQL.c \
            ReQL-expr-CPP.cpp \
            ReQL-ast-CPP.cpp \
            ReQL-CPP.cpp
	g++ -shared -o libReQL.a \
            ReQL-CPP.o \
            ReQL-ast-CPP.o \
            ReQL-expr-CPP.o \
            ReQL.o \
            ReQL-ast.o \
            ReQL-expr.o
