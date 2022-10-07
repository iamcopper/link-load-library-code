/**
 * tiny hello world 2
 *
 * Note:
 * Original source code from book, should build and link as i386 format.
 *
 * Build:
 * gcc -c -fno-builtin helloworld2.c -m32
 * ld -static -e nomain -o helloworld2 helloworld2.o -melf_i386
 *
 * ld -static -T helloworld.lds -o helloworld2 helloworld2.o -melf_i386
 */

char *str = "Hello World!\n";

void print()
{
	asm ("movl $13, %%edx \n\t"
		"movl %0, %%ecx \n\t"
		"movl $0, %%ebx \n\t"
		"movl $4, %%eax \n\t"
		"int $0x80     \n\t"
		::"r"(str):"edx", "ecx", "ebx");
}

void exit()
{
	asm( "movl $42,%ebx \n\t"
		"movl $1,%eax \n\t"
		"int $0x80    \n\t");
}

void nomain()
{
	print();
	exit();
}
