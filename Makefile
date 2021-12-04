OBJECTS = loader.o kmain.o io.o printer.o framebuffer.o font.o
CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
		 -nostartfiles -nodefaultlibs  -c
LDFLAGS = -T ./src/link.ld -melf_i386
AS = nasm
ASFLAGS = -f elf

all: kernel.elf

kernel.elf: $(OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) -o kernel.elf

os.iso: kernel.elf
	cp kernel.elf iso/boot/kernel.elf
	genisoimage -R                       \
		-b boot/grub/stage2_eltorito     \
		-no-emul-boot                    \
		-boot-load-size 4                \
		-A os                            \
		-input-charset utf8              \
		-quiet                           \
		-boot-info-table                 \
		-o os.iso                        \
		iso

run: os.iso
	qemu-system-x86_64 -cdrom os.iso

%.o: ./src/kernel/%.c
	$(CC) $(CFLAGS)  $< -o $@

%.o: ./src/asm/%.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf *.o kernel.elf os.iso
