#ifndef QUEUE_H
#define QUEUE_H

#include "task.h"

#define EEMPTY 1
#define ENULL 2

typedef struct node_t {
        task_t *task;
        struct node_t *next;
} node_t;

typedef struct queue_t {
        node_t *head;
        node_t *tail;
} queue_t;

/* Initialize a queue. */
int queue_init(queue_t **q);

/* Add task to the tail of the queue. */
int queue_add(queue_t *q, task_t *task);

/* Remove a task from the head of the queue. */
int queue_remove(queue_t *q, task_t *task);

/* Returns non-zero if the queue is empty. */
int queue_is_empty(queue_t *q);

/* Free the queue. */
int queue_destroy(queue_t **q);

#endif
