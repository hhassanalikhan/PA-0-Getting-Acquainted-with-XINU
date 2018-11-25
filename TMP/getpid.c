/* getpid.c - getpid */

#include <conf.h>
#include <kernel.h>
#include <proc.h>


/*------------------------------------------------------------------------
 * getpid  --  get the process id of currently executing process
 *------------------------------------------------------------------------
 */
 extern int tracingCalls;
extern unsigned long ctr1000;
#define SystemCAllCOunt 27
 struct processSummary
{
	int sysCallFrequency[SystemCAllCOunt];
	int sysCallExecutionAverage[SystemCAllCOunt];

};
extern struct processSummary procSummaryList[50];
SYSCALL getpid()
{
	unsigned long start = ctr1000;
	if(tracingCalls == 1)
	{
		procSummaryList[currpid].sysCallFrequency[2] += 1;
	}
	if(tracingCalls == 1)
	{
		unsigned long stop = ctr1000 - start;
		procSummaryList[currpid].sysCallExecutionAverage[2] = procSummaryList[currpid].sysCallExecutionAverage[2] + stop;
	}
	return(currpid);
}
