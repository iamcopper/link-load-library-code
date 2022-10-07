/**
 * tiny hello world
 *
 * Note:
 * Has changed code for building on x86_64
 *
 * Build:
 * gcc -c -fno-builtin helloworld.c
 * ld -static -e nomain -o helloworld helloworld.o
 * 
 * ld -static -T helloworld.lds -o helloworld helloworld.o
 */

char *str = "Hello world!\n";

void print()
{
	asm("movl $13, %%edx \n\t"
		"movq %0, %%rcx  \n\t"
		"movl $0, %%ebx  \n\t"
		"movl $4, %%eax  \n\t"
		"int $0x80       \n\t"
		::"r"(str):"edx", "ecx", "ebx");
}

void exit()
{
	asm("movl $42, %ebx \n\t"
		"movl $1,  %eax \n\t"
		"int $0x80      \n\t");
}

void nomain()
{
	print();
	exit();
}
