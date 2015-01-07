all: libReQL.a

test: libReQLtest
	./libReQLtest

check: test

OBJS = ReQL.obj \
       ReQL-ast.obj \
			 ReQL-expr.obj \
			 ReQL-new.obj \
			 ReQL-decode.o \
			 ReQL-encode.o \
			 ReQL.o \
			 ReQL-ast.o \
			 ReQL-expr.o \
			 ReQL-json.o

LDFLAGS += -pthread -shared
CXXFLAGS += -std=c++11 -fPIC
CCFLAGS += -fPIC

TESTOBJS = ReQL-test.obj ReQL-ast-test.obj ReQL-expr-test.obj

libReQL.a: $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

%.obj: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

libReQLtest: libReQL.a $(TESTOBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(TESTOBJS) $<
