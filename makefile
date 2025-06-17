CC = gcc

CFLAGS = -Wall -Wextra -std=c99 -g

OBJS = main.o quicksort.o stack.o

EXEC = quicksort_iterativo

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

main.o: main.c quicksort.h
	$(CC) $(CFLAGS) -c main.c

quicksort.o: quicksort.c quicksort.h stack.h
	$(CC) $(CFLAGS) -c quicksort.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm -f $(OBJS) $(EXEC)