#!/bin/bash

flex word.l
bison -d parse.y

gcc -c lex.yy.c -o lex.o -DYYDEBUG=1
gcc -c parse.tab.c -o parse.o -DYYDEBUG=1
gcc -c dict.c -o dict.o
gcc -c type.c -o type.o
gcc -c ir.c -o ir.o
gcc -c vm.c -o vm.o

gcc lex.o parse.o dict.o type.o ir.o vm.o -o test

#./test < test4.c > log.txt
