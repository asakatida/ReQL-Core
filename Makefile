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

LDFLAGS += -pthread
CXXFLAGS += -std=c++11 -fPIC
CCFLAGS += -fPIC

TESTOBJS = ReQL-test.obj ReQL-ast-test.obj ReQL-expr-test.obj

libReQL.a: $(OBJS)
	$(CXX) $(LDFLAGS) -shared -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

%.obj: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

libReQLtest: $(OBJS) $(TESTOBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(TESTOBJS)

