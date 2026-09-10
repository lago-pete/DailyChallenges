#include <stdio.h>


volatile int flag = 0;

int check_flag(volatile int *x){
    if(*x == 1)
    {
        return 1;
    }
    else{
        return 0;
    }
}


int main (void){
    int count = 0;
    while(count < 16){

        if(count == 3){
            flag = 1;
        }

        if(check_flag(&flag) == 1){
            printf("\n Flag is set!\n\n");
        }
        else{
            printf("\n Flag is NOT set!\n\n");
        }
        count++;
    }


    return 0;
}