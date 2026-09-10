#include <stdio.h>


int (*ptr[2])(int a, int b);



int sub(int a, int b){
    int result = a - b;
    printf("\nSubtraction: %d \n", result);
    return result;
}

int add(int a, int b){
    int result = a + b;
    printf("\n Addition: %d \n", result);
    return result;
}

int main(void){
    ptr[0] = add;
    ptr[1] = sub;

    for(int i = 0; i < 2; i++){
        ptr[i](1,3);
    }

    return 0;
}