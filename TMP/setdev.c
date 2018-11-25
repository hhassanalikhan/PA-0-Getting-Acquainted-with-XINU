/* setdev.c - setdev */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
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
 *  setdev  -  set the two device entries in the process table entry
 *------------------------------------------------------------------------
 */
SYSCALL	setdev(int pid, int dev1, int dev2)
{
	unsigned long start = ctr1000;
	if(tracingCalls == 1 )
	{
		procSummaryList[currpid].sysCallFrequency[13] += 1;
	}

	short	*nxtdev;

	if (isbadpid(pid))
		return(SYSERR);
	nxtdev = (short *) proctab[pid].pdevs;
	*nxtdev++ = dev1;
	*nxtdev = dev2;
		if(tracingCalls == 1)
	{
		unsigned long stop = ctr1000 - start;
		procSummaryList[currpid].sysCallExecutionAverage[13] += stop;
	}
	return(OK);
}
