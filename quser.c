/******************************************************************************
NAME:		quser.c
DESCRIPTION:	Definitions of functions for user processes, including a
		function to create them all on startup. Here, two processes
		are created. The first simply blocks itself. The second
		unblocks itself, and then relinquishes the processor. With
		the first process created before the second process, it will
		be executed first. Hence, it will always block itself just
		before the second process unblocks it.

		(C) 1999 by Naraig Manjikian
		Department of Electrical and Computer Engineering
		Queen's University
******************************************************************************/

#include "quser.h"
#include "qcore.h"

#define USER_STACK_SIZE 256

static  char    P1stack[USER_STACK_SIZE];
static  char    P2stack[USER_STACK_SIZE];

/*----------------------------------------------------------------*/

//From manji: You will need to produce a basic operational Nios II kernel that can handle a couple of simple processes
// that relinquish/block/unblock in the manner reflected in the sample quser.c file in the above package.
// Then extend basic
static	void    Process1 (void)
{
        for (;;)
        {
                QuerkBlockSelf (); //TODO: find this method's definition, is it in qrequest or qcore? issue possibly with IDE not recognizing connection
        }
}

static	void    Process2 (void)
{
        for (;;)
        {
			QuerkUnblock (1);
			QuerkRelinquish ();
        }
}

/*----------------------------------------------------------------*/
/* called from main program on startup */

void	UserProcesses (void)
{
	QuerkNewProcess (Process1, P1stack, USER_STACK_SIZE);
    QuerkNewProcess (Process2, P2stack, USER_STACK_SIZE);
}
