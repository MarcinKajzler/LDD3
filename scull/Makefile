#DEBUG = y

ifeq ($(DEBUG),y)
  DEBFLAGS = -O -g -DSCULL_DEBUG
else
  DEBFLAGS = -O2
endif

ccflags-y += $(DEBFLAGS)

ifeq ($(KERNELRELEASE),)

KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD       := $(shell pwd)

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
else
	scull-objs := main.o pipe.o access.o
	obj-m	:= scull.o
endif

clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions

depend .depend dep:
	$(CC) -M *.c > .depend


ifeq (.depend,$(wildcard .depend))
include .depend
endif
