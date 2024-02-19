#include "temp_api.h"
void addRecord(sensor_info_* p_info,int number,
                uint16_t year,uint8_t month,uint8_t day,uint8_t hh,uint8_t mm,int8_t t)
{
    p_info[number].year = year;
    p_info[number].month = month;
    p_info[number].day = day;
    p_info[number].hh = hh;
    p_info[number].mm = mm;
    p_info[number].t = t;
}

int addInfo(sensor_info_* p_info)
{
    int cntr;
    cntr = 0;
    addRecord(p_info,cntr++,2021,9,16,14,30,9);
    addRecord(p_info,cntr++,2022,9,2,10,45,-9);
    addRecord(p_info,cntr++,2021,1,7,2,30,8);
    addRecord(p_info,cntr++,2021,9,5,00,45,1);
    return cntr;
}

void print_sensor (sensor_info_* p_info, int number)
{
    printf("==================\n");
    for (int i = 0; i < number; i++)
    {
        printf("%04d - %02d - %02d  time %02d : %02d  temp = %3d\n",
                p_info[i].year,
                p_info[i].month,
                p_info[i].day,
                p_info[i].hh,
                p_info[i].mm,
                p_info[i].t
        );
    }
}
void changeIJ (sensor_info_* p_info,int i, int j)
{
    sensor_info_ tmp;
    tmp = p_info[i];
    p_info[i] = p_info[j];
    p_info[j] = tmp;
}

// sort by temp
void sort_by_temp(sensor_info_* p_info, int n)
{
    printf("======Sort by temp======\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (p_info[i].t > p_info[j].t)
            {
                changeIJ(p_info,i,j);
            }
        }
    }       
}
uint32_t date_to_int(sensor_info_* p_info)
{
    return p_info->year << 16 | p_info->month << 8 | p_info->day;
}
void sort_by_date(sensor_info_* p_info, int n)
{
    printf("======Sort by date======\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (date_to_int(p_info + i) >= date_to_int(p_info + j))
            {
                changeIJ(p_info,i,j);
            }
        }
    }
}
void save_in_file(sensor_info_* p_info, int n)
{
    ;;
}
void average_temp_month(sensor_info_* p_info, int n)
{
    ;;
}
void min_temp_month(sensor_info_* p_info, int n)
{
    ;;
}
void max_temp_month(sensor_info_* p_info, int n)
{
    ;;
}
void average_temp_year(sensor_info_* p_info, int n)
{
    ;;
}
void min_temp_year(sensor_info_* p_info, int n)
{
    ;;
}
void max_temp_year(sensor_info_* p_info, int n)
{
    ;;
}
