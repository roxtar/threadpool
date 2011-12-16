#include "queue.h"
#include <stdio.h>
#include <error.h>
#include <assert.h>
#include <stdlib.h>

void
die(int rc) {
    if(rc < 0) {
        fprintf(stderr, "Failed: %d", rc);
        exit(rc);
    }
}

void * test1(void *p) {
        printf("Test 1\n");
        return (void *) 0;
}

void * test2(void *p) {
        printf("Test 2\n");
        return (void *) 0;
}

int main() {
        queue_t *q;
        task_t t1 = { test1 };
        task_t t2 = { test2 };
        task_t t;

        int rc = queue_init(&q);
        die(rc);
        assert(q != NULL);

        rc = queue_add(q, &t1);
        die(rc);
        rc = queue_add(q, &t2);
        die(rc);
        assert(!queue_is_empty(q));
        
        rc = queue_remove(q, &t);
        die(rc);
        assert(t.task == t1.task);
        rc = queue_remove(q, &t);
        die(rc);
        assert(t.task == t2.task);

        rc = queue_remove(q, &t);
        assert(rc < 0);
        assert(queue_is_empty(q));

        queue_destroy(&q);

        printf("Success!\n");
        return 0;

}
