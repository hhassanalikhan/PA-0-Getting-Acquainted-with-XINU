/* receive.c - receive */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
extern unsigned long ctr1000;
 extern int tracingCalls;
#define SystemCAllCOunt 27
 struct processSummary
{
	int sysCallFrequency[SystemCAllCOunt];
	int sysCallExecutionAverage[SystemCAllCOunt];

};
extern struct processSummary procSummaryList[50];
/*------------------------------------------------------------------------
 *  receive  -  wait for a message and return it
 *------------------------------------------------------------------------
 */
SYSCALL	receive()
{
		unsigned long start = ctr1000;
	if(tracingCalls == 1)
	{
		procSummaryList[currpid].sysCallFrequency[6] += 1;
	}

	STATWORD ps;    
	struct	pentry	*pptr;
	WORD	msg;

	disable(ps);
	pptr = &proctab[currpid];
	if ( !pptr->phasmsg ) {		/* if no message, wait for one	*/
		pptr->pstate = PRRECV;
		resched();
	}
	msg = pptr->pmsg;		/* retrieve message		*/
	pptr->phasmsg = FALSE;
	restore(ps);
	if(tracingCalls == 1)
	{
		unsigned long stop = ctr1000 - start;
		procSummaryList[currpid].sysCallExecutionAverage[6] += stop;
	}
	return(msg);
}
