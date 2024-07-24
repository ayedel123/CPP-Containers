GPP = g++
CFLAGS = -std=c++17

RBTree =

test: clean
	$(GPP) $(CFLAGS) main.cc $(RBTree) -o test

test2: clean
	$(GPP) $(CFLAGS) test.cc -o test

run:
	./test

clean:
	rm -rf .out test