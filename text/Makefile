##
# Makefile for text processing library
# Author: Alexander Borodin, <aborod@petrsu.ru>
#

# Compiler
CC = gcc

# Build debug version of the library
.PHONY: debug
debug: CFLAGS += -Wall -Wextra -DDEBUG -ggdb3 -O0
debug: libtext.a

# Build release version of the library
.PHONY: release
release: CFLAGS += -DNDEBUG
release: libtext.a

# List sources and target object files 
SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

# Add all object files into the library
libtext.a: $(OBJECTS)
	ar -rcs $@ $^

# Compile all C sources into separate object files
%.o: %.c _text.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Clean phony target to remove binary files
.PHONY: clean
clean:
	rm -rf *.a *.o

