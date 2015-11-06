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

static int scull_open(struct inode *nodep, struct file *filp)
{
	return 0;
}

static ssize_t scull_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	return 0;
}

static loff_t  scull_llseek(struct file *filp, loff_t off, int whence)
{
	return 0;
}

static ssize_t scull_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	return 0;
}

static long scull_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	return 0;
}

static int scull_release(struct inode *inodep, struct file *filp)
{
	return 0;
}

static struct file_operations scull_fops =
{
	.owner   = THIS_MODULE,
	.open    = scull_open,
	.read    = scull_read,
	.llseek  = scull_llseek,
	.write   = scull_write,
	.unlocked_ioctl   = scull_ioctl,
	.release = scull_release,
};

static int __init scull_init_module(void)
{
	return 0;
}

static void __exit scull_exit_module(void)
{
}

module_init(scull_init_module);
module_exit(scull_exit_module);
