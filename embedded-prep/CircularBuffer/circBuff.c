#include <stdio.h> 
#include <stdint.h>
#include <stdbool.h>

#define BUFFER_SIZE 8

typedef struct{
    volatile int head;
    volatile int tail;
    uint8_t buffer[BUFFER_SIZE];
}RingBuffer;

RingBuffer rb;

bool push(uint8_t data)
{
    if(((rb.head + 1) % BUFFER_SIZE) == rb.tail){
        printf("\nHead Lands on Tail!\n");
        return false; //head lands on the tail
    }
    rb.buffer[rb.head] = data;
    rb.head = (rb.head + 1) % BUFFER_SIZE;
    return true;
    
}
bool pop(uint8_t *data)
{
    if(rb.tail == rb.head){
        return false;
    }
    *data = rb.buffer[rb.tail];
    rb.tail = (rb.tail + 1) % BUFFER_SIZE;
    return true; 
    
}


int main (void){
    uint8_t buf [8];
    uint8_t char1 [] = "Hello678";
    
    for(int i = 0; i < 8; i++){
        push(char1[i]);
    }

    for(int i = 0; i < 8; i++){
        pop(&buf[i]);
        printf("  %c  ",buf[i]);
    }
    

    return 0;
} 