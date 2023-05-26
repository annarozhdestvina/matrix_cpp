CC=g++
CFLAGS=-Wall -Wextra -Werror -std=c++17 #-fsanitize=address
CFLAGS2=-Wall -Wextra -std=c++17
#CFLAGS=-std=c++17 -fsanitize=address -fsanitize=undefined
GTestFlags=-lgtest -lgtest_main #-fsanitize=address -fsanitize=undefined
OPEN=open
REPORT_DIR = report

TEST_SOURCES=$(wildcard test/*.cc)
VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER=valgrind_report
# SOURCES=test/test_eq.cc test/test_mul_number.cc ...
TEST_BINARIES=$(patsubst %.cc,%.o,$(TEST_SOURCES))

%.o: %.cc
		$(CC) -c $(CFLAGS2) $< -o $@


test: test/test_main.out
	./test/test_main.out

test/test_main.out: $(TEST_BINARIES) s21_matrix.o
	$(CC) $^ $(GTestFlags) --coverage -o $@

s21_matrix.o: s21_matrix.cc s21_matrix.h
	$(CC) -c $(CFLAGS) --coverage $< -o $@

clean:
	rm -rf *.o
	rm -rf *.out
	rm -rf test/*.out test/*.o
	rm -rf valgrind_report/*.txt
	rm -rf test/*.gcno
	rm -rf *.gcda
	rm -rf report/*
	rm -rf *.gcno

leaks: clean test
	leaks -atExit -- ./test/test_main.out


valgrind: test/test_main.out
	mkdir -p $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)
	-valgrind --leak-check=full --show-reachable=no --track-origins=yes --log-file=$(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/valgrind_report.txt -s ./test/test_main.out > $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/test_report.txt
	cat $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/test_report.txt
	cat $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/valgrind_report.txt

valgrind_full: test/test_main.out
	mkdir -p $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=$(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/valgrind_full_report.txt -s ./test/test_main.out > $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/test_report.txt
	cat $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/test_report.txt
	cat $(VALGRIND_REPORT_DIRECTORY_FOR_DOCKER_CONTAINER)/valgrind_full_report.txt

gcov_report: test $(REPORT_DIR)
	gcovr -r . --html --html-details -o $(REPORT_DIR)/report.html
	$(OPEN) -a 'Google Chrome' $(REPORT_DIR)/report.html

# Создание временной папки для отчетов
$(REPORT_DIR):
	@mkdir -p $(REPORT_DIR)

