#ifndef THREADPOOL_H
#define THREADPOOL_H
#include "queue.h"
#include <pthread.h>

#define DEFAULT_N_THREADS 4

typedef struct threadpool_t {
        queue_t *task_queue;
        thread_t *thread_stat;
        pthread_mutex_t qlock;
        int nthreads;
        int is_exit;
} threadpool_t;

int threadpool_init(threadpool_t **tpool);
int threadpool_set(threadpool_t *tpool, int nthreads);
int threadpool_add_task(threadpool *tpool, void * (*task)(void *));
int threadpool_run(threadpool_t *tpool);
#endif
