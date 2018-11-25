#include <stdio.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
extern unsigned long ctr1000;
extern int tracingCalls;
#define SystemCAllCOunt 27
extern int kernelLoaded ;
 struct processSummary
{
	int sysCallFrequency[SystemCAllCOunt];
	int sysCallExecutionAverage[SystemCAllCOunt];

};
extern struct processSummary procSummaryList[50];
void syscallsummary_start()
{
	

	unsigned long start = ctr1000;
	for (int i=0;i<NPROC;i++)
	{
		for (int j=0;j<27;j++)
		{
			procSummaryList[i].sysCallFrequency[i] = 0;
			procSummaryList[i].sysCallExecutionAverage[i] = 0;

		}
	}
	//kprintf("------------------Started Tracking System Calls  ------------------%lu", start);
	tracingCalls = 1;


	unsigned long stop = ctr1000 - start;
	//kprintf("------------------Testing CTR1000------------------%d", stop);
	


}
