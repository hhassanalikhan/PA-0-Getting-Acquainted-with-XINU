
#define SystemCAllCOunt 27


extern void testFunction(int a);
extern long zfunction(long param);
void printsegaddress();
void printtos();
void printprocstks(int priority);
void syscallsummary_start();
void syscallsummary_stop();
void printsyssummary();

  int tracingCalls = 0;
//void syscallsummary_stop();
 struct processSummary
{
	int sysCallFrequency[SystemCAllCOunt];
	int sysCallExecutionAverage[SystemCAllCOunt];

} p1;
//char sysCallNames [27][] = ()
 char *callNames[27] = {
"freemem",
"chprio",
"getpid",
"getprio",
"gettime",
"kill",
"receive",
"recvclr",
"recvtim",
"resume",
"scount",
"sdelete",
"send",
"setdev",
"setnok",
"screate",
"signal",
"signaln",
"sleep",
"sleep10",
"sleep100",
"sleep1000",
"sreset",
"stacktrace",
"suspend",
"unsleep",
"wait" };
 struct processSummary procSummaryList[50];

