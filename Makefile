all: build

ReQL.o: ReQL.c
	gcc -c -o $@ $<

build: ReQL.o
	gcc -o $@
