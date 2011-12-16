#include "threadpool.h"
#include <pthread.h>
#include <stdio.h>
#include <assert.h>

void *
test1(void * args) {
        printf("Test 1\n");
        printf("Success!\n");
        return (void *) 0;
}

void *
test2(void *args) {
        printf("Test 2\n");
        printf("Success!\n");
        return (void *) 0;
}

int main() {
        threadpool_t *tpool;
        int rc = threadpool_init(&tpool);
        task_t t1 = { test1, (void *) 0};
        task_t t2 = { test2, (void *) 0};
        assert(rc == 0);
        threadpool_add_task(tpool, &t1);
        threadpool_add_task(tpool, &t2);
        threadpool_run(tpool);
        threadpool_exit(tpool);
        pthread_exit(NULL);
}

