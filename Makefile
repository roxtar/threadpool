CC=gcc
TESTS=$(wildcard *_test)
CFLAGS= -Wall -g
queue.c : queue.h

queue_test.c: queue.h

threadpool.c: threadpool.h 

%.o : %.c
	$(CC) $(CFLAGS) -c $<

queue_test: queue_test.c queue.o
	$(CC) $(CFLAGS) $^ -o $@	

threadpool_test: threadpool_test.c queue.o threadpool.o
	$(CC) $(CFLAGS) -pthread $^ -o $@

threadpool_test: 

test: queue_test threadpool_test
	./queue_test
	./threadpool_test
clean:
	rm -rf *.o *_test
