//free procsummarray
//free each index of that array 
#include <kernel.h>
#include <proc.h>
#define SystemCAllCOunt 27
 struct processSummary
{
	int sysCallFrequency[SystemCAllCOunt];
	int sysCallExecutionAverage[SystemCAllCOunt];

};
extern struct processSummary procSummaryList[50];
extern int tracingCalls;
void syscallsummary_stop()
{

	tracingCalls = 0;
	
}
