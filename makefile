CFLAGS = -I

all: xlist.o main.o 
	gcc -g xlist.o main.o -o proy
	./proy

xlist.o: xlist.c
	gcc -c xlist.c -o xlist.o

main.o: main.c
	gcc -c main.c -o main.o

xlist: 
	gcc -o xlist proy.o xlist.o 
	
