obj-m += bbb_l293d.o

KDIR=/home/heidi/work/bbb/kernel/kernel
COMPILE=arm-linux-gnueabi-
ARCH=arm


all:
	make -C $(KDIR) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(COMPILE) modules

clean:
	make -C $(KDIR) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(COMPILE) clean 
