CC=g++
#CFLAGS=-Wall -Wextra -Werror -std=c++17
CFLAGS=-std=c++17

all: Azaza

main.out: main.o 
	$(CC) main.o  -o main.out

main.o: s21_matrix.cc
	$(CC) -c s21_matrix.cc $(CFLAGS) -o main.o

Azaza: main.out
	./main.out

clean:
	rm -rf *.o
	rm -rf *.out