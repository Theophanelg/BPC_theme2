all: main

main: main.o foo.o
    cc -o main main.o foo.o

main.o: main.c
    cc -c main.c

foo.o: foo.c
    cc -c foo.c