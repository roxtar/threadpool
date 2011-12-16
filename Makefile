CC=gcc
TESTS=$(wildcard *_test)
CFLAGS= -Wall
queue.c : queue.h

queue_test.c: queue.h

%.o : %.c
	$(CC) $(CFLAGS) -c $<

queue_test: queue_test.c queue.o
	$(CC) $(CFLAGS) $^ -o $@	

test: queue_test
	./queue_test
clean:
	rm -rf *.o *_test
