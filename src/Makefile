GPP = g++
CFLAGS = -std=c++17

RBTree =

test: clean
	$(GPP) $(CFLAGS) main.cc $(RBTree) -o test

manual_test: clean
	$(GPP) $(CFLAGS) ./manual_test/main.cc -o manual_test.out

run:
	./test

run_manual:
	./manual_test.out

clean:
	rm -rf *.out