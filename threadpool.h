#ifndef THREADPOOL_H
#define THREADPOOL_H
#include "queue.h"
#include <pthread.h>

#define DEFAULT_N_THREADS 4

typedef struct threadpool_t {
        queue_t *task_queue;
        pthread_mutex_t qlock;
        int nthreads;
        int is_exit;
} threadpool_t;

int threadpool_init(threadpool_t **tpool);
int threadpool_set(threadpool_t *tpool, int nthreads);
int threadpool_add_task(threadpool_t *tpool, task_t *task);
int threadpool_run(threadpool_t *tpool);
int threadpool_exit();
#endif
