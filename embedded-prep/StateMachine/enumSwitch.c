#include <stdio.h>




typedef enum{
    ENGINE_ON,
    ENGINE_OFF,
    ENGINE_WARM,
    ENGINE_ERROR
} engine_state;


typedef enum {
    EVENT_TURN_IGNITION,
    EVENT_WAIT,
    EVENT_ERROR,
} engine_event;



engine_state motor(engine_state s, engine_event e){
    switch(s){
        case ENGINE_OFF:
            if(e == EVENT_TURN_IGNITION){
                return ENGINE_ON;
            }
            if(e == EVENT_ERROR){
                return ENGINE_ERROR;
            }
            break;
        case ENGINE_ON: 
            break;
        case ENGINE_WARM:
            break;
        case ENGINE_ERROR:
            break;
    }
}