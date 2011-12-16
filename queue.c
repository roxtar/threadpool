#include "queue.h"
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int queue_init(queue_t **q) {
        *q = (queue_t *) malloc(sizeof(queue_t));
        if(*q == NULL) 
                return -ENOMEM;
        memset(*q, 0, sizeof(queue_t));
        return 0;
}

int
queue_add(queue_t *q, task_t *task) {
        node_t *current;
        if(q == NULL)
                return -ENULL;
        current = (node_t *) malloc(sizeof(node_t));
        if(current == NULL) 
                return -ENOMEM;
        current->task = task;
        if(queue_is_empty(q))
                q->head = current;
        else 
                q->tail->next = current;
        q->tail = current;
        return 0;
}

int
queue_remove(queue_t *q, task_t *task) {
        if(q == NULL) 
                return -ENULL;
        if(queue_is_empty(q)) 
                return -EEMPTY;
        else {
                node_t *old_head = q->head;
                *task = *(old_head->task);
                q->head = q->head->next;
                if(q->head == NULL)
                        q->tail = NULL;
                free(old_head);
        }
        return 0;
}

int 
queue_is_empty(queue_t *q) {
        if(!q)
                return -ENULL;
        return (q->head == NULL);
}

int
queue_destroy(queue_t **q) {
        free(*q);
        return 0;
}
