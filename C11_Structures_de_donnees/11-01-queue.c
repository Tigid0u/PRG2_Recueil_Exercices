#include "11-01-queue.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    struct node *next;
    int data;
}node;

typedef struct list {
    node *begin;
    node *last;
}list;

void *new_queue() {
    return calloc(1, sizeof(list));
}

void free_queue(void *lst) {
    list *l = (list *)lst;
    while (l->begin != NULL) {
        pop_from_queue(lst);
    }
    free(lst);
}

void push_in_queue(void *lst, int i) {
    list *l = (list *)lst;
    node *new_node = NULL;

    new_node = (node *)calloc(1, sizeof(node));
    if (new_node == NULL) {
        printf("Failed allocating memory !\n");
        return;
    }
    new_node->data = i;
    new_node->next = NULL;

    if (size_of_queue(lst) == 0) {
        l->begin = new_node;
        l->last = new_node;
    } else {
        l->last->next = new_node;
        l->last = new_node;
    }
    //printf("Front: %d, back: %d\n", front_of_queue(lst), back_of_queue(lst));
}

void pop_from_queue(void *lst) {
    list *l = (list *)lst;
    node *tmp = NULL;
    tmp = l->begin->next;
    free(l->begin);
    l->begin = tmp;
}

int front_of_queue(void *lst) {
    list *l = (list *)lst;
    return l->begin->data;
}

int back_of_queue(void *lst) {
    list *l = (list *)lst;
    return l->last->data;
}

int size_of_queue(void *lst) {
    list *l = (list *)lst;
    node *temp = NULL;
    int count = 1;
    if (l->begin == NULL || l->last == NULL) return 0;
    temp = l->begin;
    while (temp->next != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
