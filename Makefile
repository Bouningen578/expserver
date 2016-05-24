CC=gcc
VPATH = src
CFLAGS = -Iinclude -Wall --pedantic-errors -O2
TARGET = expserver
OBJDIR = ./obj
SOURCES = main.c exp1.c
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o:%.c
	@[ -d $(OBJDIR) ]
	$(CC) $(CFLAGS) -c $< -o $@

all: clean $(TARGET)
	
clean:
	rm -f $(OBJECTS) $(TARGET)
