#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>


void testFunction(int a)
{
	kprintf("\n ----------------- this is the passed var %d",a);
}
