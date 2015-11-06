#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/types.h>
#include <linux/proc_fs.h>
#include <linux/fcntl.h>
#include <linux/aio.h>
#include <linux/cdev.h>

#include "scull.h"

MODULE_AUTHOR("Marcin Kajzler");
MODULE_LICENSE("Dual BSD/GPL");

int scull_major = SCULL_MAJOR;
int scull_minor = 0;
int scull_nr_devs = SCULL_NR_DEVS;
int scull_quantum = SCULL_QUANTUM;
int scull_qset = SCULL_QSET;

struct scull_dev *scull_devices;

static int __init scull_init_module(void)
{
	return 0;
}

static void __exit scull_exit_module(void)
{
}

module_init(scull_init_module);
module_exit(scull_exit_module);
