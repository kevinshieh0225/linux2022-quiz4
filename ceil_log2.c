#include<stdio.h>
#include <stdint.h>
int ceil_log2(uint32_t x)
{
    int cps = (x & (x-1)) != 0;
    uint32_t r, shift;

    r = (x > 0xFFFF) << 4;                                                                                                                                    
    x >>= r;
    shift = (x > 0xFF) << 3;
    x >>= shift;
    r |= shift;
    shift = (x > 0xF) << 2;
    x >>= shift;
    r |= shift;
    shift = (x > 0x3) << 1;
    x >>= shift;
    return (r | shift | x >> 1) + cps;       
}

int main()
{
    printf("%d\n",ceil_log2(0));
    printf("%d\n",ceil_log2(1022));
    printf("%d\n",ceil_log2(1024));
    printf("%d\n",ceil_log2(0xFFFFF));
    printf("%d\n",ceil_log2(0xFFFF1));

}
