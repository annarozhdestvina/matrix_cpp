CC=g++
#CFLAGS=-Wall -Wextra -Werror -std=c++17
CFLAGS=-Wall -Wextra -std=c++17
CFLAGS=-std=c++17
GTestFlags=-lgtest -lgtest_main

all: Azaza

test: test/test.out
	./test/test.out

test/test.out: test/test.o s21_matrix.o
	$(CC) $^ $(GTestFlags) -o $@

s21_matrix.o: s21_matrix.cc s21_matrix.h
	$(CC) -c $(CFLAGS) $< -o $@

test/test.o: test/test.cc s21_matrix.h
	$(CC) -c $(CFLAGS) $< -o $@

#main.out: main.o 
#$(CC) main.o $(GTestFlags) -o main.out

#main.o: s21_matrix.cc s21_matrix.h
#	$(CC) -c s21_matrix.cc $(CFLAGS) -o $@

Azaza: main.out
	./main.out

clean:
	rm -rf *.o
	rm -rf *.out
	rm -rf test/*.out test/*.o