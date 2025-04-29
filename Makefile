CC=gcc
OUT_NAME=kjsh
CC_OPTIONS=-o ${OUT_NAME} -std=c99 -Wall -Wextra -Werror
DESTDIR=/usr/local/bin
BINNAME=brainfuck

all: build

build: main.c
	${CC} ${CC_OPTIONS} main.c

clean: 
	rm ${OUT_NAME}
