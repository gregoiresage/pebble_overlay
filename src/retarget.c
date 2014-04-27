#include <pebble.h>

extern unsigned int Image$$HEAP$$ZI$$Base;
extern unsigned int Image$$STACKS$$ZI$$Limit;

struct __initial_stackheap {
    unsigned heap_base; /* low-address end of initial heap */
    unsigned stack_base; /* high-address end of initial stack */
    unsigned heap_limit; /* high-address end of initial heap */
    unsigned stack_limit; /* unused */
};

__value_in_regs struct __initial_stackheap __user_initial_stackheap(
        unsigned R0, unsigned SP, unsigned R2, unsigned SL)
{
    struct __initial_stackheap config;

    config.heap_base = (unsigned int)&Image$$HEAP$$ZI$$Base;
    config.stack_base = (unsigned int)&Image$$STACKS$$ZI$$Limit;

    return config;
}
