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
    printf("0 : %d\n",ceil_log2(0));
    printf("1 : %d\n",ceil_log2(1));
    printf("2 : %d\n",ceil_log2(2));
    printf("5 : %d\n",ceil_log2(5));
    printf("8 : %d\n",ceil_log2(8));
    printf("1022 : %d\n",ceil_log2(1022));
    printf("1044 : %d\n",ceil_log2(1024));
    printf("0xFFFFF : %d\n",ceil_log2(0xFFFFF));
    printf("0xFFFF1 : %d\n",ceil_log2(0xFFFF1));
}
