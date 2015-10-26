#include <linux/init.h>
#include <linux/module.h>


MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Hello world kernel module example");
MODULE_AUTHOR("Marcin Kajzler <Marcin.Kajzler(at)gmail.com>");

static int __init hello_world_init(void)
{
	printk(KERN_ALERT "Hello world from kernel module!\n");
	return 0;
}

static void __exit hello_world_exit(void)
{
	printk(KERN_ALERT "Good bye from kernel module!\n");
}


module_init(hello_world_init);
module_exit(hello_world_exit);

