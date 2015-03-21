#include <stdint.h>

int mul(uint64_t a, uint64_t b, uint64_t *result)
{
    asm volatile goto ("mov %[a], %%rax\n\t"
                       "mul %[b]\n\t"
                       "jo %l[overflow]\n\t"
                       "mov %%rax, (%[result])"
                       :
                       : [a] "r" (a), [b] "r" (b), [result] "r" (result)
                       : "rax", "rdx"
                       : overflow);
    return (0);

overflow:
    return (1);
}
