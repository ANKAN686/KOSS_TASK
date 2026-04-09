// hello.c
#include <linux/init.h>   // Required for module_init and module_exit macros
#include <linux/module.h> // Required for all kernel modules
#include <linux/kernel.h> // Required for KERN_DEBUG and printk

// Module metadata
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ankan Dey");
MODULE_DESCRIPTION("A simple Hello World Linux Kernel Module");
MODULE_VERSION("0.1");

// Initialization function called when the module is loaded
static int __init hello_init(void) {
    // printk is the kernel's version of printf. 
    // KERN_DEBUG specifies the log level.
    printk(KERN_DEBUG "Hello World!\n");
    return 0; // Return 0 to indicate successful loading
}

// Exit function called when the module is unloaded
static void __exit hello_exit(void) {
    printk(KERN_DEBUG "Goodbye World!\n");
}

// Register the initialization and exit functions
module_init(hello_init);
module_exit(hello_exit);