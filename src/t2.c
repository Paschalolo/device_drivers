

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>


void tasklet_function1(struct tasklet_struct* t){
	pr_info("running %s\n" , __FUNCTION__);
}


DECLARE_TASKLET(my_tasklet , tasklet_function1);

static int __init my_init(void) {

	tasklet_schedule(&my_tasklet) ; 
	pr_info("tasklet example\n");
	return 0;
}

static void __exit my_exit(void){
	tasklet_kill(&my_tasklet); 
	pr_info("tassklet finished\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Paschal Ahanmisi");
