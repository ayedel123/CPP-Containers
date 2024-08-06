GPP = gcc -std=c++17 
CFLAGS = -Wall -Werror -Wextra

RBTree =

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
			 ./test/stack_test.cc \
			 ./test/vector_test.cc \
			 ./test/list_test.cc \
			 ./test/queue_test.cc



test: clean
	$(GPP) $(CFLAGS) $(TEST_SOURCES)  $(TESTFLAGS) -o test.out

gcov_report: test
	$(GPP) $(CFLAGS) $(TEST_SOURCES)  $(TESTFLAGS) $(GCOV) -o test_cov.out
	./test_cov.out
	@lcov -t "gcov_report" -o report.info --no-external -c -d .
	@genhtml -o report report.info
	@make clean_gcov
	open report/index.html

man_test: clean
	$(GPP) $(CFLAGS) $(CONTAINERS_SOURCES) ./manual_test/main.cc -o test.out

run:
	./test.out

valgrind:
	valgrind --tool=memcheck --leak-check=yes  ./test.out

clean:
	rm -rf *.out *.gcda *.gcno *.dSYM report *.info
