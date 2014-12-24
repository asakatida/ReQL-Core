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
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

ReQL.o: ReQL.c
	$(CC) $(CCFLAGS) -c $<

ReQL-ast.o: ReQL-ast.c
	$(CC) $(CCFLAGS) -c $<

ReQL-expr.o: ReQL-expr.c
	$(CC) $(CCFLAGS) -c $<

ReQL-json.o: ReQL-json.c
	$(CC) $(CCFLAGS) -c $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

libReQLtest: libReQL.a $(TESTOBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(TESTOBJS) $<
