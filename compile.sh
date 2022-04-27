#!/bin/sh
clear
flags="-std=c11 -Wall -Wpedantic -Wextra"
cc main.c $flags -o main.out
