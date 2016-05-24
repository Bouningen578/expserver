CC=gcc
VPATH = src
CFLAGS = -Iinclude -Wall --pedantic-errors
TARGET = expserver
$(TARGET): main.o exp1.o
	$(CC) $(CFLAGS) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) -c $<
