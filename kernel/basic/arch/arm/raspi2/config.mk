CPU = cortex-a7
#QEMU_FLAGS = -cpu $(CPU) -M raspi2 -m 1024M -serial mon:stdio -nographic -display none
QEMU_FLAGS = -cpu $(CPU) -M raspi2 -m 1024M -serial mon:stdio
ARCH_QEMU_CFLAGS = -mcpu=$(CPU) -DA_CORE