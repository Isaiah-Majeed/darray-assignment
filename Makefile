CC = gcc
CFLAGS = -Wall -Werror -g

all: main

main: main.o mylib.a
    $(CC) $(CFLAGS) main.o -Llib -lmylib -o main

mylib.a: mylib.o
    ar rcs lib/mylib.a obj/mylib.o

main.o: main.c
    $(CC) $(CFLAGS) -c main.c -o obj/main.o

mylib.o: mylib.c mylib.h
    $(CC) $(CFLAGS) -c mylib.c -o obj/mylib.o

clean:
    rm -f obj/*.o lib/*.a main
