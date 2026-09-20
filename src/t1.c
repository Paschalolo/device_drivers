

#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/time.h>
#include <linux/delay.h>
#include <linux/workqueue.h>

static DECLARE_WAIT_QUEUE_HEAD(my_q);

static int condition = 0 ; 

static struct work_struct wrk ; 

static void work_handler(struct work_struct* work){
	pr_info("Waitqueue module handler %s\n" , __FUNCTION__); 

	msleep(5000); 
	pr_info("Wake up from sleeping module \n"); 
	condition = 1 ; 
	wake_up_interruptible(&my_q);

}

static int __init my_init(void) {
	pr_info("Wait queue examples\n"); 

	INIT_WORK(&wrk,work_handler);
	schedule_work(&wrk); 
	pr_info("GOing to sleep %s\n" , __FUNCTION__);
	if(wait_event_interruptible(my_q, condition != 0 )) {
		pr_info("Our sleep has been interupted \n");
		return -ERESTARTSYS;
			}
	pr_info("Woken up by work job\n");
	return 0 ; 
}
static void __exit my_exit(void){
	pr_info("Wait quueu example cleanup");
}

module_init(my_init); 
module_exit(my_exit);

MODULE_AUTHOR("Paschal Ahanmisi");
MODULE_LICENSE("GPL");
