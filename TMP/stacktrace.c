/* stacktrace.c - stacktrace */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

extern unsigned long ctr1000;
 extern int tracingCalls;
static unsigned long	*esp;
static unsigned long	*ebp;

#define SystemCAllCOunt 27
 struct processSummary
{
	int sysCallFrequency[SystemCAllCOunt];
	int sysCallExecutionAverage[SystemCAllCOunt];

};
extern struct processSummary procSummaryList[50];
#define STKDETAIL

/*------------------------------------------------------------------------
 * stacktrace - print a stack backtrace for a process
 *------------------------------------------------------------------------
 */
SYSCALL stacktrace(int pid)
{
	unsigned long start = ctr1000;
	if(tracingCalls == 1)
	{
		procSummaryList[currpid].sysCallFrequency[23] += 1;
	}
    struct pentry    *proc = &proctab[pid];
    unsigned long    *sp, *fp;

    if (pid != 0 && isbadpid(pid))
        return SYSERR;
    if (pid == currpid) {
 register unsigned long    *sp1 asm("esp");
 register unsigned long    *fp1 asm("ebp");
    //    asm("movl %esp,esp");
    //    asm("movl %ebp,ebp");
        sp = esp = sp1;
        fp = ebp = fp1;

	} else {
		sp = (unsigned long *)proc->pesp;
		fp = sp + 2; 		/* where ctxsw leaves it */
	}
	kprintf("sp %X fp %X proc->pbase %X\n", sp, fp, proc->pbase);
#ifdef STKDETAIL
	while (sp < (unsigned long *)proc->pbase) {
		for (; sp < fp; sp++)
			kprintf("DATA (%08X) %08X (%d)\n", sp, *sp, *sp);
		if (*sp == MAGIC)
			break;
		kprintf("\nFP   (%08X) %08X (%d)\n", sp, *sp, *sp);
		fp = (unsigned long *) *sp++;
		if (fp <= sp) {
			kprintf("bad stack, fp (%08X) <= sp (%08X)\n", fp, sp);
			return SYSERR;
		}
		kprintf("RET  0x%X\n", *sp);
		sp++;
	}
	kprintf("MAGIC (should be %X): %X\n", MAGIC, *sp);
	if (sp != (unsigned long *)proc->pbase) {
		kprintf("unexpected short stack\n");
		return SYSERR;
	}
#endif
	        			if(tracingCalls == 1)
	{
		unsigned long stop = ctr1000 - start;
		procSummaryList[currpid].sysCallExecutionAverage[23] += stop;
	}
	return OK;
}
