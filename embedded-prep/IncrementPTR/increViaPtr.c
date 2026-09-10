#include <stdio.h>



void increment(int *y){
    *y = *y + 1;
    return;
}


int main (void){

    int x = 0;
    printf("\n%d -> ", x);
    int *ptr = &x;
    increment(ptr);
    printf("%d\n\n", x);

    return 0;
}