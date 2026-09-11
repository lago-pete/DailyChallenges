#include <stdio.h>
#include <unistd.h>

volatile int flag = 0;
typedef enum
{
    STATE_INIT,
    STATE_WAIT_IX,
    STATE_STREAMING,
    STATE_ERROR
} State;
State (*state_ptr[4])(volatile int *x);

State state_init(volatile int *x)
{
    printf("\nInintializing...\n");
    sleep(2);
    return STATE_WAIT_IX;
}

State state_wait(volatile int *x)
{
    printf("\nWaiting for GPS lock...\n");
    sleep(2);
    if (*x == 0)
    {
        printf(".");
        sleep(1);
        return STATE_WAIT_IX;
    }
    sleep(2);
    printf("\n----GPS locked----\n");
    sleep(2);
    return STATE_STREAMING;
}

State state_stream(volatile int *x)
{
    if (*x == 1)
    {
        printf("\nGPS COORDS: 387489324\n");
        sleep(2);
        return STATE_STREAMING;
    }
    else
    {
        return STATE_WAIT_IX;
    }
}

State state_error(volatile int *x)
{
    printf("\nGPS COORDS: ERROR\n");
    return STATE_ERROR;
}

int main(void)
{
    State current_state = STATE_INIT;
    state_ptr[STATE_INIT] = state_init;
    state_ptr[STATE_WAIT_IX] = state_wait;
    state_ptr[STATE_STREAMING] = state_stream;
    state_ptr[STATE_ERROR] = state_error;
    int count = 0;

    while (count < 100)
    {
        if (count % 3 == 0)
        {
            if (flag == 0)
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }
        }
        if (current_state < 0 || current_state > STATE_ERROR)
        {
            printf("Invalid state!\n");
            break;
        }

        current_state = state_ptr[current_state](&flag);

        count++;
    }
}
