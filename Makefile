##
# Makefile for simple line editor
# Author: Alexander Borodin, <aborod@petrsu.ru>
#

# Compiler
CC = gcc

# Linker
LD = gcc

# Build debug version of the editor
debug: MFLAGS += debug
debug: CFLAGS += -Wall -Wextra -DDEBUG -g -O0
debug: editor

# Build release version of the editor
release: MFLAGS += release
release: CFLAGS += -DNDEBUG
release: editor

# List sources and target object files 
SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

# Build editor
editor: $(OBJECTS) text
	$(LD) $(LDFLAGS) -o editor $(OBJECTS) -L./text -ltext

# Build text processing library
.PHONY: text
text: 
	cd text && $(MAKE) $(MFLAGS)

# Compile editor
%.o: %.c text/text.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Clean phony target to remove binary files
.PHONY: clean
clean:
	cd text && $(MAKE) $@
	rm -rf *.o editor

