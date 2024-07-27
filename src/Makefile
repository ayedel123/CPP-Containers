GPP = g++
CFLAGS = -std=c++17

RBTree =
TESTFLAGS=-lgtest -lgtest_main -lrt -lstdc++ -pthread -lm -g
GCOV = -lgcov --coverage -fprofile-arcs -ftest-coverage

TEST_SOURCES = ./test/s21_containers_test.cc \
			 ./test/s21_map_test.cc \
			#./test/s21_set_test.cc

test: clean
	$(GPP) $(CFLAGS)  $(TEST_SOURCES)  $(TESTFLAGS) -o test.out

manual_test: clean
	$(GPP) $(CFLAGS) ./manual_test/main.cc -o manual_test.out

run:
	./test.out

run_manual:
	./manual_test.out

clean:
	rm -rf *.out