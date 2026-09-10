#include <stdio.h>

float c_to_f (float celsius){
    float f = celsius *1.8 + 32;
    return f;
}


int main (void){
    float celsius = 100;
    double print = c_to_f(celsius);
    printf("The Conversion from %f Celsius to Fahrenheit is : %f\n", celsius, print);
    
    return 0;
}