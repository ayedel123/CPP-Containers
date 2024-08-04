GPP = g++
CFLAGS = -std=c++17

RBTree =
#TESTFLAGS=-lgtest -lgtest_main -lrt -lstdc++ -pthread -lm -g
GCOV = -lgcov --coverage -fprofile-arcs -ftest-coverage

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
TESTFLAGS=-lgtest -lgtest_main -lrt -lstdc++ -pthread -lm -g
endif
ifeq ($(UNAME), Darwin)
TESTFLAGS=-lgtest -lgtest_main -lstdc++ -pthread -lm -g
endif

TEST_SOURCES = ./test/containers_test.cc \
			 ./test/map_test.cc \
			 ./test/set_test.cc \
			 ./test/rbtree_test.cc \
			 ./test/multiset_test.cc

test: clean
	$(GPP) $(CFLAGS)  $(TEST_SOURCES)  $(TESTFLAGS) -o test.out

man_test: clean
	$(GPP) $(CFLAGS) ./manual_test/main.cc -o test.out

run:
	./test.out

valgrind:
	valgrind --tool=memcheck --leak-check=yes  ./test.out

clean:
	rm -rf *.out