#include <stdio.h>
//#include <kernel.h>
extern int edata;
extern int etext;
extern int end;
void printsegaddress()
{
	kprintf("\n\n void printsegaddress()");

	kprintf("\n Current: etext[%08x]=%08x, edata[%08x]=%08x, ebss[%08x]=%08x",&etext, *(&etext),&edata, *(&edata),&end,*(&end) );
	kprintf("\n Before: etext[%08x]=%08x, edata[%08x]=%08x, ebss[%08x]=%08x",&etext -1, *(&etext - 1),&edata-1, *(&edata-1),&end-1,*(&end-1));
	kprintf("\n After: etext[%08x]=%08x, edata[%08x]=%08x, ebss[%08x]=%08x",&etext+1, *(&etext+1),&edata+1, *(&edata+1),&end+1,*(&end+1));
	
	// data segment
	/*kprintf("\n End of data segment Content : %08x",edata);
	kprintf("\n End of data segment Address : %08x",&edata);
	kprintf("\n 4 bytes Content before data segment end (at address= %08x): %08x",(&edata-1),*(&etext-1));
	kprintf("\n 4 bytes Content after data segment end (at address= %08x): %08x",(&edata+1),*(&edata+1));
	//text segment
	kprintf("\n End of text segment Content : %08x",etext);
	kprintf("\n End of text segment Address : %08x",&etext);
	kprintf("\n 4 bytes Content before text segment end (at address= %08x): %08x",(&etext-1),*(&etext-1));
	kprintf("\n 4 bytes Content after text segment end (at address= %08x): %08x",(&etext+1),*(&etext+1));
	//text segment
	kprintf("\n End of BSS segment Content : %08x",end);
	kprintf("\n End of BSS segment Address : %08x",&end);
	kprintf("\n 4 bytes Content before BSS segment end (at address= %08x): %08x",(&end-1),*(&end-1));
	kprintf("\n 4 bytes Content after BSS segment end (at address= %08x): %08x",(&end+1),*(&end+1));*/
	
}


//(int *) (at address= 0002057d): c35b08c4

