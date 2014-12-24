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

CXX = $(CXX) $(CXXFLAGS)
CC = $(CC) $(CCFLAGS)

TESTOBJS = ReQL-test.o ReQL-ast-test.o ReQL-expr-test.o

libReQL.a: $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

ReQL.o: ReQL.c
	$(CC) -c $<

ReQL-ast.o: ReQL-ast.c
	$(CC) -c $<

ReQL-expr.o: ReQL-expr.c
	$(CC) -c $<

ReQL-json.o: ReQL-json.c
	$(CC) -c $<

%.o: %.cpp
	$(CXX) -o $@ -c $<

libReQLtest: libReQL.a $(TESTOBJS)
	$(CXX) -o $@ $(TESTOBJS) $<
