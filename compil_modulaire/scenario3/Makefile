all : main

main : main.o
	cc -o main main.o foo.o

main.o : main.cc
	cc -o main.c 

foo.o : foo.c
	cc -c foo.c