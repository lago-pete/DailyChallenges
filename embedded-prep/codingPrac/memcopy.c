// Implement memcpy — copy n bytes from src to dest and return dest.

// Assumptions (classic interview contract): regions do not overlap. If they might overlap, use memmove.

// Do not call the standard library memcpy.

// Example:

// src  = {1,2,3,4}
// n    = 4
// dest = {0,0,0,0}
// → dest becomes {1,2,3,4}; return dest

#include <stdio.h>

void* memcopy(void *dest, const void *src, size_t n){
    unsigned char *d = (unsigned char *) dest;
    const unsigned char *s = (unsigned char *) src;

    printf("\n size of N: %ld \n", n);
    for(int i = 0; i < n; i++){
        d[i] = s[i];
    }
    return dest;
}


int main(void){
    int src[] = {1,2,3,4};
    int n = sizeof(src); 
    int dest[] = {0,0,0,0};
    int *ptr = dest;
    int *ptr2 = src;

    memcopy(ptr, ptr2, n);


    for(int i = 0; i < 4; i++){
        printf("%d", dest[i]);
    }
    printf("\n");
    

    return 0;
}

