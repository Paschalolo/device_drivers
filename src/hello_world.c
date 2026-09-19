#include <linux/module.h>
#include <linux/init.h> 


static int __init hello_world_init(void){
	pr_info("Hello world initialization");
	return 0 ; 
}

static void  __exit hello_world_fini(void){
	pr_info("Finito");
	return  ; 
}

module_init(hello_world_init);
module_exit(hello_world_fini);
MODULE_LICENSE("GPL"); 
MODULE_AUTHOR("Paschal Ahanmisi");
MODULE_DESCRIPTION("Hello Kernel MOdule");
