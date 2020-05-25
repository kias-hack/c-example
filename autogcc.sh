# !/bin/bash

gcc -c main.c
gcc -c getsizearray.c
gcc -o toupper main.o getsizearray.o
rm main.o
rm getsizearray.o
