/* scount.c - scount */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <sem.h>
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
 *  scount  --  return a semaphore count
 *------------------------------------------------------------------------
 */
SYSCALL scount(int sem)
{
extern	struct	sentry	semaph[];

	unsigned long start = ctr1000;
	if(tracingCalls == 1)
	{
		procSummaryList[currpid].sysCallFrequency[10] += 1;
	}
	if (isbadsem(sem) || semaph[sem].sstate==SFREE)
		return(SYSERR);
	if(tracingCalls == 1)
	{
		unsigned long stop = ctr1000 - start;
		procSummaryList[currpid].sysCallExecutionAverage[10] += stop;
	}
	return(semaph[sem].semcnt);
}
