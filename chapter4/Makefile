out := helloworld_x32 helloworld_x64

all: $(out)

clean:
	-rm $(out) *.o

helloworld_x64: helloworld_x64.o
	ld -static -e nomain -o $@ $^

helloworld_x32: helloworld_x32.o
	ld -static -e nomain -o $@ $^ -melf_i386

helloworld_x64.o: helloworld_x64.c
	gcc -c -fno-builtin $^

helloworld_x32.o: helloworld_x32.c
	gcc -c -fno-builtin $^ -m32

.PHONY: all clean
