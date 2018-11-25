/* user.c - main */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>


extern int tracingCalls;
int prX;
void halt();
/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */
prch(c)
char c;
{
	kprintf("\n For Pid %D",getpid());
	chprio(getpid(), 33);
	chprio(getpid(), 32);
	int i;
	//sleep(1);	
}
int main()
{

	long int param = 2864434397;
	kprintf("\n\nHello World, Xinu lives\n\n");
	kprintf ("\nReturned value of zfunction %08x",zfunction(param));
	printsegaddress();
	printtos();
	printprocstks(5);
	syscallsummary_start();  
	sleep(1);
	resume(prX = create(prch,2000,20,"proc X",1,'A'));
	syscallsummary_stop();
	printsyssummary();

	return 0;
}
