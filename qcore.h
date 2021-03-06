#ifndef _QCORE_H_
#define _QCORE_H_

/******************************************************************************
NAME:		qcore.h
DESCRIPTION:	Type definitions and function declarations for core of
		QUERK kernel.

		(C) 1999 by Naraig Manjikian
		Department of Electrical and Computer Engineering
		Queen's University
******************************************************************************/

typedef enum {Ready, Running, Blocked} State;

typedef struct  _process // Formerly _pdb
{
        struct  _process    *prev;
        struct  _process    *next;
        int     pid; // process id
        State   state;
		// TODO: Best to name user stack pointer or stack pointer? formerly just SP
        void    *user_stack_pointer;		/* saves user stack pointer when not running */
} Process; // Formerly pdb

#define MAX_NUM_OF_PROCESSES 16

extern  void    QuerkNewProcess (void (*entry_point) (void),
				 char *stack_bottom, int stack_size);

extern  void    QuerkSWIHandler (void);

extern  void    QuerkDispatch (void);

#endif /* _QCORE_H_ */
