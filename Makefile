CC=gcc
OUT_NAME=kjsh
CFLAGS=-o ${OUT_NAME} -std=c99 -Wall -Wextra -Werror -Iinclude
SOURCE=$(shell find src -name '*.c')
DESTDIR=/usr/local/bin
BINNAME=brainfuck

all: build

build: src/*
	${CC} ${CFLAGS} ${SOURCE}

debug: src/*
	${CC} ${CFLAGS} -DDEBUG ${SOURCE}

clean: 
	rm ${OUT_NAME}
