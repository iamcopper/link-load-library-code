out := helloworld helloworld2

all: helloworld helloworld2

clean:
	-rm $(out) *.o

helloworld: helloworld.o
	ld -static -e nomain -o $@ $^

helloworld2: helloworld2.o
	ld -static -e nomain -o $@ $^ -melf_i386

helloworld.o: helloworld.c
	gcc -c -fno-builtin $^

helloworld2.o: helloworld2.c
	gcc -c -fno-builtin $^ -m32

