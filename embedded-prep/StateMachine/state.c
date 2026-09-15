#include <stdio.h>

typedef enum
{
    GEAR_UP,
    GEAR_LOWERING,
    GEAR_DOWN_LOCKED,
    GEAR_FAULT,
} state_gear;

typedef enum
{
    EVT_LOWER_CMD,
    EVT_LOCK_SENSED,
    EVT_SENSOR_FAIL,
    EVT_MAINTENANCE_RESET,
} events_gear;

state_gear state_handler(state_gear s, events_gear e)
{

    switch (s)
    {
    case GEAR_UP:
        if (e == EVT_LOWER_CMD)
            return GEAR_LOWERING;
        break;
    case GEAR_LOWERING:
        if (e == EVT_LOCK_SENSED)
            return GEAR_DOWN_LOCKED;
        if (e == EVT_SENSOR_FAIL)
            return GEAR_FAULT;
        break;
    case GEAR_DOWN_LOCKED:
        break;
    case GEAR_FAULT:
        if (e == EVT_MAINTENANCE_RESET)
            return GEAR_UP;
        break;
    }
    return s;
}

int main(void)
{

    int choice;
    state_gear s = GEAR_UP;
    printf("\n Gears Currently Up\n");
    while (1)
    {

        printf("\n Event Selection: 1.EVT_LOWER_CMD  2.EVT_LOCK_SENSED 3.EVT_SENSOR_FAIL 4.EVT_MAINTENANCE_RESET \n");
        printf("\n Enter Choice: ");
        scanf("%d", &choice);
        choice--;
        system("clear");
        events_gear e = (events_gear)choice;
        s = state_handler(s, e);
        switch (s)
        {
        case GEAR_UP:
            printf("\nGEARS UP....\n");
            break;
        case GEAR_LOWERING:
            printf("\nGEARS LOWERING....\n");
            break;
        case GEAR_DOWN_LOCKED:
            printf("\nCommense Landing\n");
            break;
        case GEAR_FAULT:
            printf("\nFAULT TRY RESET....\n");
            break;
        }
    }

    return 0;
}