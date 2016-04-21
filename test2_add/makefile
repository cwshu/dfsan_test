CC = clang
CFLAGS = -std=c99 -Wall

all: main main2

main: main.c add.o dfsan_abilist.txt
	${CC} ${CFLAGS} -fsanitize=dataflow -fsanitize-blacklist=dfsan_abilist.txt main.c add.o -o main

main2: main.c add.o dfsan_abilist2.txt
	${CC} ${CFLAGS} -fsanitize=dataflow -fsanitize-blacklist=dfsan_abilist2.txt main.c add.o -o main2

add.o: add.c
	${CC} ${CFLAGS} -c add.c -o add.o

clean:
	rm -f main main2 *.o
