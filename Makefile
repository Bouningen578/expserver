VPATH = src
CPPFLAGS = -I include
main: main.c
	$(CC) $(CFLAGS) $^ -o $@
