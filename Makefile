.PHONY: all

EXE = test_linked_list

OBJECTS = linked_list.o

CC = gcc
CSTANDARD = c99
override CFLAGS += -std=$(CSTANDARD) -Wall -Werror

all: $(EXE)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(EXE): $(EXE).c $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXE) $(EXE).c $(OBJECTS)

clean:
	rm -rf $(OBJECTS) $(EXE)

test: $(EXE)
	valgrind --leak-check=yes ./$(EXE)


