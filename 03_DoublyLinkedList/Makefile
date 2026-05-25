all: build run

build:
	clang -g -O0 -Wall -o test *.c

run: build
	./test

clean:
	rm -f test test_asan test.dSYM

asan:
	clang -fsanitize=address -g -O0 -o test_asan *.c && ./test_asan

.PHONY: all build run clean asan
