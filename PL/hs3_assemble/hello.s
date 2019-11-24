.text		#section declatration
		#we must exprot the entry point to the ELF linker or
.global _start	#loader, they conventionally recognize _start as their
		#entry point. Use ld -e foo to override the default.
_start:
		#write the string to stout
   movl $len, %edx	#third argument: message length
   movl $msg, %ecx	#second argument: pointer to message to write
   movl $1, %ebx 	#firtst argument: file handle (stdout)
   movl $4, %eax	#system call number (sys_write)
   int $0x80		#i = interupt / call kernel
			#and exit

   movl $0, %ebx	#first argument : exit code
   movl $1, %eax	#system call number (sys_exit)
   int $0x80		#call kernel
	
.data			#section declaraiton
msg:
.ascii "Hellow, world!\n"	#string
len = . - msg			#length of the string

