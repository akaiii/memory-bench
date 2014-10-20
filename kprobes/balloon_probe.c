#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/kallsyms.h>

struct kprobe kp;

int handler_pre(struct kprobe *p, struct pt_regs *regs)
{
	static int i = 0;
	printk("Number: %d\n",i++);
	dump_stack();
	return 0;
}

static __init int init_kprobe_sample(void)
{
	kp.symbol_name = "balloon_process";
	
	kp.pre_handler = handler_pre;

	register_kprobe(&kp);

	return 0;
	
}

module_init(init_kprobe_sample);

static __exit void cleanup_kprobe_sample(void)
{
	unregister_kprobe(&kp);
}

module_exit(cleanup_kprobe_sample);

MODULE_LICENSE("GPL");

