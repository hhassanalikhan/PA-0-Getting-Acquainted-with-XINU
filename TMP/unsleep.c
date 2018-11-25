/* unsleep.c - unsleep */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
extern unsigned long ctr1000;
#define SystemCAllCOunt 27
 struct processSummary
{
	int sysCallFrequency[SystemCAllCOunt];
	int sysCallExecutionAverage[SystemCAllCOunt];

};
extern struct processSummary procSummaryList[50];
 extern int tracingCalls;
/*------------------------------------------------------------------------
 * unsleep  --  remove  process from the sleep queue prematurely
 *------------------------------------------------------------------------
 */
SYSCALL	unsleep(int pid)
{
		unsigned long start = ctr1000;
	if(tracingCalls == 1 )
	{
		procSummaryList[currpid].sysCallFrequency[25] += 1;
	}
	STATWORD ps;    
	struct	pentry	*pptr;
	struct	qent	*qptr;
	int	remain;
	int	next;

        disable(ps);
	if (isbadpid(pid) ||
	    ( (pptr = &proctab[pid])->pstate != PRSLEEP &&
	     pptr->pstate != PRTRECV) ) {
		restore(ps);
		return(SYSERR);
	}
	qptr = &q[pid];
	remain = qptr->qkey;
	if ( (next=qptr->qnext) < NPROC)
		q[next].qkey += remain;
	dequeue(pid);
	if ( (next=q[clockq].qnext) < NPROC)
		sltop = (int *) & q[next].qkey;
	else
		slnempty = FALSE;
        restore(ps);
    if(tracingCalls == 1)
	{
		unsigned long stop = ctr1000 - start;
		procSummaryList[currpid].sysCallExecutionAverage[25] += stop;
	}
	return(OK);
}
