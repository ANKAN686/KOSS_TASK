obj-m += linux_task.o

KDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

all:
	@if [ ! -d "$(KDIR)" ]; then \
		echo "Kernel build directory not found: $(KDIR)"; \
		echo "Set KDIR=/path/to/kernel/build or install matching kernel headers."; \
		exit 1; \
	fi
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	@if [ -d "$(KDIR)" ]; then \
		$(MAKE) -C $(KDIR) M=$(PWD) clean; \
	else \
		rm -f *.o *.ko *.mod *.mod.c Module.symvers modules.order; \
		rm -rf .tmp_versions; \
	fi
