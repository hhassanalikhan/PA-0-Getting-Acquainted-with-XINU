/* chprio.c - chprio */
#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <stdio.h>
 extern int tracingCalls;
extern unsigned long ctr1000;
#define SystemCAllCOunt 27
 struct processSummary
{
	int sysCallFrequency[SystemCAllCOunt];
	int sysCallExecutionAverage[SystemCAllCOunt];

};
extern struct processSummary procSummaryList[50];
/*------------------------------------------------------------------------
 * chprio  --  change the scheduling priority of a process
 *------------------------------------------------------------------------
 */
SYSCALL chprio(int pid, int newprio)
{

unsigned long start = ctr1000;
	//kprintf("changing priority for %d",currpid);
	STATWORD ps;    
	struct	pentry	*pptr;
	if(tracingCalls == 1)
	{
//kprintf("changing priority for %d",currpid);
		procSummaryList[currpid].sysCallFrequency[1] += 1;
//kprintf("Freq %d",procSummaryList[currpid].sysCallFrequency[1]);
	}

	disable(ps);
	if (isbadpid(pid) || newprio<=0 ||
	    (pptr = &proctab[pid])->pstate == PRFREE) {
		restore(ps);
		return(SYSERR);
	}
	pptr->pprio = newprio;
	restore(ps);
	if(tracingCalls == 1)
	{
		unsigned long stop = ctr1000 - start;
		procSummaryList[currpid].sysCallExecutionAverage[1] = procSummaryList[currpid].sysCallExecutionAverage[1] + stop;
	}
	
	return(newprio);
}
