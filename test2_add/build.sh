#!/bin/sh

clang -c add.c -o add.o
clang -fsanitize=dataflow -fsanitize-blacklist=dfsan_abilist.txt main.c add.o -o main
clang -fsanitize=dataflow -fsanitize-blacklist=dfsan_abilist2.txt main.c add.o -o main2
