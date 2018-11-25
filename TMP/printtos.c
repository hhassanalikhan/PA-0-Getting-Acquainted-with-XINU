#include <stdio.h>
//static unsigned int *cesp;
void printtos()
{
	kprintf("\n\n void printtos()");
	register unsigned int *cesp asm("esp");
	kprintf("\n Before[%08x]= %08x \n After [%08x]= %08x", cesp,*(cesp),(cesp-3), *(cesp+3));
	//asm("movl %esp,cesp");
	for(int i=1;i<5;i++)
		kprintf("\n Content below the top of stack [%08x] = %08x",(cesp+i), *(cesp+i));
		
}
