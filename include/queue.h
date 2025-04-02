
#ifndef QUEUE_H
#define QUEUE_H

#include "common.h"

#define MAX_QUEUE_SIZE 10

struct queue_t {
	struct pcb_t * proc[MAX_QUEUE_SIZE];
	int size;
};

void enqueue(struct queue_t * q, struct pcb_t * proc);

struct pcb_t * dequeue(struct queue_t * q);

int empty(struct queue_t * q);
//SUPPORT FUNCTION
void swap(struct queue_t *q, int idx1, int idx2);
void reheapUp(struct queue_t *q, int position);
void reheapDown(struct queue_t *q, int position);


#endif

