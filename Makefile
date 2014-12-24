all: libReQL.a

test: libReQLtest
	./libReQLtest

OBJS = ReQL-CPP.o \
       ReQL-ast-CPP.o \
			 ReQL-expr-CPP.o \
			 ReQL.o \
			 ReQL-ast.o \
			 ReQL-expr.o \
			 ReQL-json.o

LDFLAGS += -shared
CXXFLAGS += -std=c++11 -fPIC
CCFLAGS += -fPIC

TESTOBJS = ReQL-test.o ReQL-ast-test.o ReQL-expr-test.o

libReQL.a: $(OBJS)
	g++ $(LDFLAGS) -o $@ $(OBJS)

ReQL.o: ReQL.c
	gcc $(CCFLAGS) -c $<

ReQL-ast.o: ReQL-ast.c
	gcc $(CCFLAGS) -c $<

ReQL-expr.o: ReQL-expr.c
	gcc $(CCFLAGS) -c $<

ReQL-json.o: ReQL-json.c
	gcc $(CCFLAGS) -c $<

%.o: %.cpp
	g++ $(CXXFLAGS) -o $@ -c $<

libReQLtest: libReQL.a $(TESTOBJS)
	g++ -o libReQLtest $(TESTOBJS) libReQL.a
