all: libReQL.a

test: libReQLtest
	./libReQLtest

clean:
	rm -f *.o *.obj

check: test

rebuild: clean all test

OBJS = ReQL.obj \
	ReQL-ast.obj \
	ReQL-expr.obj \
	ReQL-new.obj \
	ReQL-decode.o \
	ReQL-encode.o \
	ReQL.o \
	ReQL-ast.o \
	ReQL-char.o \
	ReQL-cursor.o \
	ReQL-expr.o \
	ReQL-json.o

LDFLAGS += -pthread -std=c++11
CXXFLAGS += -fPIC -std=c++11 -Weverything -Wall -Wextra -Werror -pedantic -pedantic-errors -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-exit-time-destructors -Wno-padded -Wno-non-virtual-dtor -Wno-weak-vtables
CCFLAGS += -fPIC -std=c11 -Weverything -Wall -Wextra -Werror -pedantic -pedantic-errors -Wno-padded

TESTOBJS = ReQL-test.obj ReQL-ast-test.obj ReQL-expr-test.obj

libReQL.a: $(OBJS)
	$(CXX) $(LDFLAGS) -shared -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

%.obj: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

libReQLtest: $(OBJS) $(TESTOBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(TESTOBJS)
