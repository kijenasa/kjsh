CC=gcc
OUT_NAME=kjsh
CC_OPTIONS=-o ${OUT_NAME} -std=c99 -wall -wextra -werror
DESTDIR=/usr/local/bin
BINNAME=brainfuck

all: build

build: main.c
	${CC} ${CC_OPTIONS} main.c

clean: 
	rm ${OUT_NAME}
