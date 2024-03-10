#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
enum { SIZE_INF = 527040, /*527040*/
       MAX_NUM = 6,
};
typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hh;
    uint8_t mm;
    int8_t t;
}sensor_info_;

typedef struct { 
    uint16_t year;
    uint8_t month;
    float average_temp_month;
    int8_t min_temp_month;
    int8_t max_temp_month;

}out_stat_month_;
typedef struct { 
    uint16_t year;
    float average_temp_year;
    int8_t min_temp_year;
    int8_t max_temp_year;
}out_stat_year_;

void info_app(void);
void print_sensor (sensor_info_* p_info, int number);
void sort_by_date(sensor_info_* p_info, int n);
void sort_by_temp(sensor_info_* p_info, int n);
uint32_t date_to_int(sensor_info_* p_info);

void average_temp_month(sensor_info_* p_info,int n,out_stat_month_* p_stat);
void min_temp_month(sensor_info_* p_info,int n,out_stat_month_* p_stat);
void max_temp_month(sensor_info_* p_info,int n,out_stat_month_* p_stat);
void average_temp_year(out_stat_month_* pst_month,out_stat_year_* p_year);
void min_temp_year(out_stat_month_* pst_month,out_stat_year_* p_year);
void max_temp_year(out_stat_month_* pst_month,out_stat_year_* p_year);
void print_out_stat_year (out_stat_year_* p_info);
void print_out_stat_month (out_stat_month_* p_info);
int print_out_stat_this_month (out_stat_month_* p_info,int num_month);




