all: floppya.img bootloader_in_floppy kernel_in_floppy
run: all
	- bochs -f opsys.bxrc -q
kernel.bin: start.o kernel.o kernel_asm.o
	ld86 -o $@ -d $^
kernel.o: kernel.c
	bcc -ansi -c -o $@ $<
kernel_asm.o: kernel.asm
	as86 $< -o $@
start.o: start.asm
	as86 $< -o $@
bootload.bin: bootload.asm
	nasm $< -f bin -o $@
bootloader_in_floppy: floppya.img bootload.bin
	dd if=bootload.bin of=floppya.img bs=512 count=1 conv=notrunc 
	touch bootloader_in_floppy

kernel_in_floppy: floppya.img kernel.bin
	dd if=kernel.bin of=floppya.img bs=512 seek=3 conv=notrunc 
	touch kernel_in_floppy

floppya.img: 
	dd if=/dev/zero of=floppya.img bs=512 count=2880
	dd if=map.img of=floppya.img bs=512 count=1 seek=1 conv=notrunc
	dd if=dir.img of=floppya.img bs=512 count=1 seek=2 conv=notrunc
	
clean:
	rm -f *.o kernel_in_floppy bootloader_in_floppy
	rm -f *.bin
	
wipe: clean
	rm -f floppya.img
