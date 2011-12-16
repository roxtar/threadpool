#include "threadpool.h"
#include "task.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *
worker_loop(void *arg) {
        threadpool_t *tpool = (threadpool_t *) arg;
        pthread_mutex_t *lock = &(tpool->qlock);
        while(1) {
                while(queue_is_empty(tpool->task_queue) &&
                      !tpool->is_exit);
                if(tpool->is_exit) {
                        pthread_exit(NULL);
                        return (void *) 0;
                }
                pthread_mutex_lock(lock);
                if(queue_is_empty(tpool->task_queue)) {
                        pthread_mutex_unlock(lock);
                        continue;
                } 
                else {
                        task_t task;
                        int rc = queue_remove(tpool->task_queue, &task);
                        if(rc < 0) {
                                printf("Error removing task from task queue: %d.", rc);
                                pthread_mutex_unlock(lock)
                                continue;
                        }
                        else {
                                pthread_mutex_unlock(lock);
                                task->task(task->args);
                        }
                }                
        }
}

int
threadpool_init(threadpool_t **tpool) {
        int rc;
        *tpool = (threadpool_t *)malloc(sizeof(threadpool_t));
        if(*tpool == NULL) 
                return -ENOMEM;
        memset(*tpool, 0, sizeof(threadpool_t));
        rc = queue_init((*tpool)->task_queue);
        if(rc < 0)
                return rc;
        pthread_mutex_init(&(tpool->qlock), NULL);
        (*tpool)->nthreads = DEFAULT_N_THREADS;
        return 0;
}

int
threadpool_set(threadpool_t *tpool, int nthreads) {
        if(tpool == NULL)
                return -ENULL;
        tpool->nthreads = nthreads;
}

int
threadpool_add_task(threadpool *tpool, void *(*task)(void *)) {
        pthread_mutex_t *lock = &(tpool->qlock);
        pthread_mutex_lock(lock);
        queue_add(tpool->task_queue, task);
        pthread_mutex_unlock(lock);
}

int
threadpool_run(threadpool_t *tpool) {
}
        
