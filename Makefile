CC=gcc
VPATH = src
CFLAGS = -Iinclude -Wall --pedantic-errors -O2
TARGET = expserver
OBJDIR = ./obj
INCLUDEDIR = ./include
HEADERS = exp1.h portnum.h
SOURCES = main.c exp1.c
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
INCLUDES = $(addprefix $(INCLUDEDIR)/, $(HEADERS:.c=.o))
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: %.c $(INCLUDES)
	@[ -d $(OBJDIR) ]
	$(CC) $(CFLAGS) -c $< -o $@

all: clean $(TARGET)
	
clean:
	rm -f $(OBJECTS) $(TARGET)


