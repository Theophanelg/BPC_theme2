gcc -c put_numbers.c -o o/put_numbers.o
gcc -c numbers_test.c -o o/numbers_test.o
gcc o/put_numbers.o o/numbers_test.o -o o/test_numbers