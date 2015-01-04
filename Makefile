all: libReQL.a

test: libReQLtest
	./libReQLtest

OBJS = ReQL-CPP.obj \
       ReQL-ast-CPP.obj \
			 ReQL-expr-CPP.obj \
			 ReQL-decode.o \
			 ReQL-encode.o \
			 ReQL.o \
			 ReQL-ast.o \
			 ReQL-expr.o \
			 ReQL-json.o

LDFLAGS += -pthread -shared
CXXFLAGS += -std=c++11 -fPIC
CCFLAGS += -fPIC

TESTOBJS = ReQL-test.o ReQL-ast-test.o ReQL-expr-test.o

libReQL.a: $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

%.obj: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

libReQLtest: libReQL.a $(TESTOBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(TESTOBJS) $<
