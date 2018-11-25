//free procsummarray
//free each index of that array 
#include <kernel.h>
#include <proc.h>
extern int tracingCalls;
#define SystemCAllCOunt 27
 struct processSummary
{
	int sysCallFrequency[SystemCAllCOunt];
	int sysCallExecutionAverage[SystemCAllCOunt];

};
extern char *callNames[27];
extern struct processSummary procSummaryList[50];
int firstrun = 0;
void printsyssummary()
{

	kprintf("\nvoid printsyscallsummary()");
	int pprinted = 0;

	//calling summary for each process
	for(int i = 0; i < NPROC; i++ )
	{
		
		//summary printing for all syscalls of i-th process
		for(int j = 0;j < 27; j++)
		{
			if(procSummaryList[i].sysCallFrequency[j] > 0)
			{
				//PRINT NAME OF ONE PROCESS only once when its sum of syscall > 0
				if(pprinted == 0)
				{
					kprintf("\nProcess [pid:%d]", i);
					pprinted = 1;
				}
				kprintf("\n\tSyscall: %s, count: %d, average execution time: %d (ms)", callNames[j], procSummaryList[i].sysCallFrequency[j], procSummaryList[i].sysCallExecutionAverage[j]/procSummaryList[i].sysCallFrequency[j] );
			}

		}
		pprinted = 0;
	}
	//reinit tracing control variable
	
}
