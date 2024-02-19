#include "temp_api.h"
int main(void)
{
    sensor_info_ sensor_inf[SIZE_INF];
    int number= addInfo(sensor_inf);
    print_sensor(sensor_inf,number);
    sort_by_temp(sensor_inf,number);
    print_sensor(sensor_inf,number);
    sort_by_date(sensor_inf,number);
    print_sensor(sensor_inf,number);
    return 0;
}