#include <stdio.h>


typedef struct{
    int (*init)(void);
    int (*read)(float *out);
}Sensor_ops_t;


int print_gps_init(void){
    printf("\nGPS INIT\n");
    return 1;
}
int print_BME_init(void){
    printf("\nBME INIT\n");
    return 1;
}

int read_gps(float *out){
    return *out * 2;
}

int read_BME(float *out){
    return *out * 3;
}

static const Sensor_ops_t gps_ops ={ .init = print_gps_init, .read = read_gps};
static const Sensor_ops_t bme_ops ={ .init = print_BME_init, .read = read_BME};


void sensor_poll_all (Sensor_ops_t *sensors[], int size){
    float count = 1;
    for (int i = 0; i < size; i++)
    {
        printf("\nSensor NUMBER: %d\n",sensors[i] -> read(&count));
    }
    return;
}



int main (void){
    Sensor_ops_t *arr[2];
   

    float gps = 1;
    float bme = 1;

    gps_ops.init();
    bme_ops.init();
    printf("\nGPS NUMBER: %d\n",gps_ops.read(&gps));
    printf("\nBME NUMBER: %d\n",bme_ops.read(&bme));


    sensor_poll_all(arr, 2);
    

    return 0;
}