CC=g++
#CFLAGS=-Wall -Wextra -Werror -std=c++17
CFLAGS=-Wall -Wextra -std=c++17
CFLAGS=-std=c++17
GTestFlags=-lgtest -lgtest_main

TEST_SOURCES=$(wildcard test/*.cc)
# SOURCES=test/test_eq.cc test/test_mul_number.cc ...
TEST_BINARIES=$(patsubst %.cc,%.o,$(TEST_SOURCES))




%.o: %.cc
		$(CC) -c $(CFLAGS) $< -o $@
	

# all: Azaza


test: test/test_main.out
	./test/test_main.out

# test/test_main.out: test/test_main.o s21_matrix.o test/test_eq.o test/test_mul_number.o
test/test_main.out: $(TEST_BINARIES) s21_matrix.o
	$(CC) $^ $(GTestFlags) -o $@

# test/test_eq.o: test/test_eq.cc s21_matrix.h
# 	$(CC) -c $(CFLAGS) $< -o $@

# test/test_mul_number.o: test/test_mul_number.cc s21_matrix.h
# 	$(CC) -c $(CFLAGS) $< -o $@

# test/test_main.o: test/test_main.cc
# 	$(CC) -c $(CFLAGS) $< -o $@


s21_matrix.o: s21_matrix.cc s21_matrix.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf *.o
	rm -rf *.out
	rm -rf test/*.out test/*.o