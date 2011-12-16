queue.c : queue.h

%.o : %.c
	$(CC) -c $<

clean:
	rm -rf *.o
