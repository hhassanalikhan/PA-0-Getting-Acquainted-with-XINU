#include <stdio.h>
#include <kernel.h>
#include <proc.h>

void printprocstks(int prior)
{
	kprintf("\n\nvoid printprocstks(int priority)");
	for(int i=0;i<NPROC;i++)
	{
		if(prior < proctab[i].pprio &&  proctab[i].pstate != PRFREE)
		{
			kprintf("\n Process : %s", proctab[i].pname);
			kprintf("\n\t pid : %d", i);
			kprintf("\n\t Priority : %d", proctab[i].pprio);
			kprintf("\n\t base : %08x", proctab[i].pbase);
			kprintf("\n\t limit : %08x", proctab[i].plimit);
			kprintf("\n\t len : %d", proctab[i].pstklen);
			if(i!=currpid)
			{
				kprintf("\n\t stack pointer : %08x", proctab[i].pesp);
			}
			else
			{
				register unsigned int *cesp asm("esp");
				kprintf("\n\t stack pointer : %08x",cesp);
			}
			
			
			
			
		}
	}
}
/*
pid: 11
	priority: 40
	base: 0x00ff0ff0
	limit: 0x00ffffff
	len: 1024
	pointer: 0x 00ffff22*/
