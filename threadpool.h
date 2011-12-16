#ifndef THREADPOOL_H
#define THREADPOOL_H
int threadpool_init(int nthreads);
int threadpool_set(int nthreads);
int threadpool_run(void *(*task)(void *));
#endif
