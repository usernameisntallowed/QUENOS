/******************************************************************************
NAME:		queue.c
DESCRIPTION:	Definitions of process descriptor queue management functions.

		(C) 1999 by Naraig Manjikian
		Department of Electrical and Computer Engineering
		Queen's University
******************************************************************************/

#include "qcore.h"
#include "queue.h"

/*----------------------------------------------------------------*/

void    AddToTail (Queue *queue, Process *process)
{
        process->prev = queue->tail;
        process->next = 0;
        if (queue->head != 0)
                queue->tail->next = process;
        else
                queue->head = process;
        queue->tail = process;
}

Process     *DequeueHead (Queue *queue)
{
        Process     *ret;

        ret = queue->head;
        if (ret == 0)
                return ret;

        queue->head = ret->next;
        if (queue->head == 0)
                queue->tail = 0;
        else
                queue->head->prev = 0;

        return ret;
}
