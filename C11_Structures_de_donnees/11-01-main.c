#include <stdio.h>

#include "11-01-queue.h"

int main() {
    void *q = new_queue();

    for (int i = 0; i < 10; ++i) {
        push_in_queue(q, i * i);
        if (i % 2 == 0) {
            printf("%d ", front_of_queue(q));
            pop_from_queue(q);
        }
    }

    printf("\n%d elements remain in queue, from %d to %d.\n",
        size_of_queue(q),
        front_of_queue(q),
        back_of_queue(q));

    free_queue(q);
}
