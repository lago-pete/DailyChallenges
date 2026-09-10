#include <stdio.h>

int (*ptr)(int a,int b);

int add(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}


int main (void){
    int result = 0;
    ptr = add;
    result = ptr(2,1);
    printf("\nAddition %d\n",result);
    ptr = sub;
    result = ptr(5,5);
    printf("\nSubtraction %d\n\n", result);

    return 0;
}