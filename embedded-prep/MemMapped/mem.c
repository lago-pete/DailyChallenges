#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>



 typedef struct{
    volatile uint32_t CR;
    volatile uint32_t SR;
    volatile uint32_t DR;
 }USART_T;


 #define USART1 ((USART_T *)0x40011000U)


 void sendToDR (uint8_t byte){
    while(!(USART1->SR &( 1 << 7))){
    };
    USART1->DR = byte;
 }