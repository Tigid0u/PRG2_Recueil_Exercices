#ifndef QUEUE_H
#define QUEUE_H

void *new_queue();
void free_queue(void *);

void push_in_queue(void *, int i);
void pop_from_queue(void *);
int front_of_queue(void *);
int back_of_queue(void *);
int size_of_queue(void *);

#endif
