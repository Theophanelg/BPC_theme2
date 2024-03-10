CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic

all : numbers_test

numbers_test: numbers_test.o put_numbers.o
	$(CC) $(CFLAGS) $ˆ -o $@

put_numbers.o: put_numbers.c
	$(CC) $(CFLAGS) -c $^ -o o/$@

numbers_test.o: numbers_test.c
	$(CC) $(CFLAGS) -c $^ -o o/$@

clean:
	rm -f numbers-test o/*.o