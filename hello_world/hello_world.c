#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>


MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Hello world kernel module example");
MODULE_AUTHOR("Marcin Kajzler <Marcin.Kajzler(at)gmail.com>");

#define ARR_SIZE 3
static char *message = "Default_message";
static int rep = 0;
static int arr[ARR_SIZE] = {5,10,15};
static int read_cnt = 0;

static int __init hello_world_init(void)
{
	int i;
	printk(KERN_ALERT "Hello world from kernel module!\n");
	for ( i=0; i<rep; ++i)
	{
		printk(KERN_INFO "Rep %d: %s\n",i,message);
	}
	if (read_cnt)
		printk(KERN_INFO "Array values: %d, %d, %d\n", arr[0], arr[1], arr[2]);
	return 0;
}

static void __exit hello_world_exit(void)
{
	printk(KERN_ALERT "Good bye from kernel module!\n");
}


module_init(hello_world_init);
module_exit(hello_world_exit);
//message can not contain spaces
module_param(message, charp, S_IRUGO);
module_param(rep, int, S_IRUGO);
module_param_array(arr, int, &read_cnt, S_IRUGO);

