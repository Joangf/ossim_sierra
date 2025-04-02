#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t *q)
{
    if (q == NULL)
        return 1;
    return (q->size == 0);
}

void enqueue(struct queue_t *q, struct pcb_t *proc)
{
    /* TODO: put a new process to queue [q] */
    if (q->size >= MAX_QUEUE_SIZE)
        return;
    q->proc[q->size] = proc;
    reheapUp(q, q->size);
    q->size++;
}

struct pcb_t *dequeue(struct queue_t *q)
{
    /* TODO: return a pcb whose prioprity is the highest
     * in the queue [q] and remember to remove it from q
     * */
    if (q->size <= 0)
        return NULL;
    struct pcb_t *ret = q->proc[0];
    swap(q, 0, q->size - 1);
    q->size--;
    reheapDown(q, 0);
    return ret;
}
// SUPPORT FUNCTION
void swap(struct queue_t *q, int idx1, int idx2)
{
    struct pcb_t *temp = q->proc[idx1];
    q->proc[idx1] = q->proc[idx2];
    q->proc[idx2] = temp;
}

void reheapUp(struct queue_t *q, int position)
{
    if (position == 0)
        return;
    int idxRhs = (position - 1) / 2;
    if (q->proc[position]->priority < q->proc[idxRhs]->priority)
    {
        swap(q, position, idxRhs);
        reheapUp(q, idxRhs);
    }
}
void reheapDown(struct queue_t *q, int position)
{
    if (position * 2 + 1 >= q->size)
        return;
    int idxRhs1 = position * 2 + 1;
    int idxRhs2 = position * 2 + 2;
    int idx;
    if (idxRhs2 < q->size)
    {
        if (q->proc[idxRhs1]->priority < q->proc[idxRhs2]->priority)
            idx = idxRhs1;
        else
            idx = idxRhs2;
    }
    else
        idx = idxRhs1;
    if (q->proc[position]->priority > q->proc[idx]->priority)
    {
        swap(q, position, idx);
        reheapDown(q, idx);
    }
}