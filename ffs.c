#define BITS_PER_BYTE 8
#define BITS_PER_LONG (sizeof(unsigned long) * BITS_PER_BYTE)

#include <stddef.h>
#include <stdio.h>

static inline size_t _ffs(unsigned long x)
{
    if (x == 0)
        return 0;
    
    int r, shift;
    
    r = (BITS_PER_LONG == 64 && ((x & 0xFFFFFFFF) == 0)) << 5;
    x >>= r;
    
    shift = ((x & 0xFFFF) == 0) << 4;
    x >>= shift;
    r |= shift;
    
    shift = ((x & 0xFF) == 0) << 3;
    x >>= shift;
    r |= shift;
    
    shift = ((x & 0xF) == 0) << 2;
    x >>= shift;
    r |= shift;
    
    shift = ((x & 0x3) == 0) << 1;
    x >>= shift;
    r |= shift;
    
    return r + ((x & 0x1) == 0);
}

int main()
{
    printf("0 : %ld\n",_ffs(0));
    printf("1 : %ld\n",_ffs(1));
    printf("2 : %ld\n",_ffs(2));
    printf("0x8 : %ld\n",_ffs(0x8));
    printf("0x80 : %ld\n",_ffs(0x80));
    printf("0x4000 : %ld\n",_ffs(0x4000));
    printf("0x8000000000 : %ld\n",_ffs(0x8000000000));
    printf("0xFFF8000 : %ld\n",_ffs(0xFFF8000));
}