#ifndef TASK_H
#define TASK_H

typedef struct task_t {
    void * (*task) (void *);
}task_t;
#endif
