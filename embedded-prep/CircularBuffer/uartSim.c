#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define RB_SIZE 8
#define RB_MASK (RB_SIZE - 1)


typedef struct{
    volatile uint8_t buff[RB_SIZE];
    volatile uint16_t head;
    volatile uint16_t tail;
}ringbuf_t;


bool rb_put(ringbuf_t *rb, uint8_t data){
    uint16_t next = (rb->head + 1) & RB_MASK;
    if(next == rb->tail) return false; 
    rb->buff[rb->head] = data;
    rb->head = next;
    return true;
}


bool rb_get(ringbuf_t *rb, uint8_t *data){
    if(rb->head == rb->tail) return false;
    *data = rb->buff[rb->tail];
    uint16_t next = (rb->tail + 1) & RB_MASK;
    rb->tail = next;
    return true; 
}





int main(void){
    static ringbuf_t rb;
    uint8_t data;
    uint8_t good_input[5] = {1,2,3,4,5};
    uint8_t bad_input[9] = {1,2,3,4,5,6,7,8,9};

    for(int i = 0; i < 9; i++){
        bool result = rb_put(&rb, bad_input[i]);
        if(result == false)
        {
            printf("\nToo much Data!!!!\n");
        }
    }

    printf("\n Printing what's inside the rb.buffer: ");

    for(int i = 0; i < RB_SIZE; i++){
        printf("%d, ",rb.buff[i]);
    }

    bool result = true;
    result = rb_get(&rb, &data);
    printf("\nData Pulled From the RB.Buffer: ");
    while(result){
        printf(" %d ,", data);
        result = rb_get(&rb, &data);
    }
    printf("\n");


}