#include <stdio.h>
#include <string.h>
#include <stdint.h>

enum { SIZE_INF = 30,

};
typedef struct {
    uint16_t year;
    uint8_t day;
    uint8_t month;
    uint8_t hh;
    uint8_t mm;
    int8_t t;
}sensor_info_;

void addRecord(sensor_info_* p_info,int number,uint16_t year,uint8_t month,uint8_t day,uint8_t hh,uint8_t mm,int8_t t);
int addInfo(sensor_info_* p_info);
void print_sensor (sensor_info_* p_info, int number);
void sort_by_date(sensor_info_* p_info, int n);
void sort_by_temp(sensor_info_* p_info, int n);
uint32_t date_to_int(sensor_info_* p_info);
/////empty prototypes ///
void save_in_file(sensor_info_* p_info, int n);
void average_temp_month(sensor_info_* p_info, int n);
void min_temp_month(sensor_info_* p_info, int n);
void max_temp_month(sensor_info_* p_info, int n);
void average_temp_year(sensor_info_* p_info, int n);
void min_temp_year(sensor_info_* p_info, int n);
void max_temp_year(sensor_info_* p_info, int n);





