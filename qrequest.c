/******************************************************************************
NAME:		qrequest.c
DESCRIPTION:	Definitions for functions to request specific kernel services.
		In-line assembly code is used to produce the software interrupt
		that is necessary to enter the kernel. The type of request is
		passed to the kernel (i.e., pushed on the stack with the
		interrupt) in accumulator A. If another parameter is needed
		(as in the case of blocking), it is passed in accumulator B.
		Because accumulator A is the high 8 bits of accumulator D,
		the request code is shifted left by 8 bits. The 'addd #0' is
		needed only because without it, there is no way of passing
		the request type to the in-line assembly code. The compiler
		generates code before the code in quotations below to set
		the contents of accumulator D, but only if the code in
		quotations has an instruction like 'addd #0' that actually
		uses accumulator D.

		(C) 1999 by Naraig Manjikian
		Department of Electrical and Computer Engineering
		Queen's University
******************************************************************************/

#include "qrequest.h"

void    QuerkRelinquish (void)
{
        _asm ("addd #0\nswi", ((unsigned int) Relinquish << 8));
}

void    QuerkBlockSelf (void)
{
        _asm ("addd #0\nswi", ((unsigned int) BlockSelf << 8));
}

void    QuerkUnblock (int other_pid)
{
        _asm ("addd #0\nswi",
              ((unsigned int) Unblock << 8) | other_pid);
}

