/* sleep100.c - sleep100 */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
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
 * sleep100  --  delay the caller for a time specified in 1/100 of seconds
 *------------------------------------------------------------------------
 */
SYSCALL sleep100(int n)
{
		unsigned long start = ctr1000;
		if(proctab[currpid].pstate != PRFREE && tracingCalls == 1 )
	{
		procSummaryList[currpid].sysCallFrequency[20] += 1;
	}
	STATWORD ps; 


	if (n < 0  || clkruns==0)
	         return(SYSERR);
	disable(ps);
	if (n == 0) {		/* sleep100(0) -> end time slice */
	        ;
	} else {
		insertd(currpid,clockq,n*10);
		slnempty = TRUE;
		sltop = &q[q[clockq].qnext].qkey;
		proctab[currpid].pstate = PRSLEEP;
	}
	resched();
        restore(ps);
        			if(proctab[currpid].pstate != PRFREE && tracingCalls == 1)
	{
		unsigned long stop = ctr1000 - start;
		procSummaryList[currpid].sysCallExecutionAverage[20] += stop;
	}
	return(OK);
}
