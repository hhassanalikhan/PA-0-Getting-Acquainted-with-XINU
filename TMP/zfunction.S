.global zfunction
zfunction:
	mov 0x8(%esp), %eax  	 #move the first pushed 8bytes argument to eax
	and $0xfffc01ff,%eax	 #clear the 9th and 7 bit of argument but doing the AND operation 
	shr $0x08,%eax		 #Right shift of 8 bits
	or $0xff000000,%eax	 # set 8 bits on the left to 1
	ret
