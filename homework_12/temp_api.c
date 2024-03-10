#include "temp_api.h"
#include "stdio.h"
void info_app(void)
{
    printf("This app is about temperature sensor's statistic.\n");
    printf("Get parameters of command line:\n");
    puts("-h : HELP;");
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
void print_out_stat_year (out_stat_year_* p_info)
{
    printf("==================\n");
    
    printf("Year :%04d Min temp in year: %02d Max temp in year: %02d  average_temp:%.4f\n",
            p_info->year,
            p_info->min_temp_year,
            p_info->max_temp_year,
            p_info->average_temp_year
     );
    
}
void print_out_stat_month (out_stat_month_* p_info)
{
    int ind;
    ind = 0;
    printf("==================\n");
    printf("Year : %04d\n",p_info[ind].year);
    while (p_info[ind].month >0)
    {
        printf("month is :%02d Min temp in month: %02d Max temp in month: %02d  average_temp:%.4f\n",
            p_info[ind].month,
            p_info[ind].min_temp_month,
            p_info[ind].max_temp_month,
            p_info[ind].average_temp_month
        );
        ind++;
    }
}
int print_out_stat_this_month (out_stat_month_* p_info, int num_month)
{
    int ind;
    ind = 0;
    while (p_info[ind].month >0)
    {
        if (p_info[ind].month == num_month)
        {
            printf("Month is :%02d Min temp in month: %02d Max temp in month: %02d  average_temp:%.4f\n",
                p_info[ind].month,
                p_info[ind].min_temp_month,
                p_info[ind].max_temp_month,
                p_info[ind].average_temp_month
            );
            return 0;
        }
        ind++;
    }
    return 1;
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
void average_temp_month(sensor_info_* p_info, int n,out_stat_month_* p_stat)
{
    float average_temp;
    int denum;
    int ind;
    ind = 0;
    denum = 0;
    average_temp = 0.0;
    for (int cntr = 0; cntr < n - 1; cntr++)
    {
           
        if (p_info[cntr].month == p_info[cntr+1].month)
        {
            average_temp += p_info[cntr].t;
            denum++;
        }
        else
        {
            average_temp += p_info[cntr].t;
            denum++;
            average_temp  = average_temp /(float) denum;
            p_stat[ind].year =  p_info[cntr].year;
            p_stat[ind].month = p_info[cntr].month;
            p_stat[ind].average_temp_month = average_temp;
            average_temp = 0.0;
            denum = 0;
            ind++;
        }         
    }
    p_stat[ind].year =  p_info[n-1].year;
    p_stat[ind].month = p_info[n-1].month;
    p_stat[ind].average_temp_month = p_info[n-1].t;
}
void min_temp_month(sensor_info_* p_info,int n,out_stat_month_* p_stat)
{
    int ind;
    ind = 0;
    int8_t min_temp;
    min_temp = p_info[0].t;
    for (int cntr = 0; cntr < n - 1; cntr++)
    {
        if (p_info[cntr].month == p_info[cntr+1].month) // check if it is the same month
        {
            if (p_info[cntr+1].t < min_temp)
            {
                min_temp = p_info[cntr+1].t;
            }  
        }
        else // save min temperature for this month
        {  
            p_stat[ind].min_temp_month = min_temp;
            min_temp =  p_info[cntr+1].t;
            ind++;   
        }  
    }
    p_stat[ind].min_temp_month = min_temp;
}
void max_temp_month(sensor_info_* p_info, int n,out_stat_month_* p_stat)
{
    int ind;
    ind = 0;
    int8_t max_temp;
    max_temp = p_info[0].t;
    for (int cntr = 0; cntr < n - 1; cntr++)
    {
        if (p_info[cntr].month == p_info[cntr+1].month) // check if it is the same month
        {
            if (p_info[cntr+1].t > max_temp)
            {
                max_temp = p_info[cntr+1].t;
            } 
        }
        else
        {
            // save max temperature for this month
            p_stat[ind].max_temp_month = max_temp;
            max_temp =  p_info[cntr+1].t;
            ind++;    
        }     
    }
    p_stat[ind].max_temp_month = max_temp;
}
void average_temp_year(out_stat_month_* pst_month,out_stat_year_* p_year)
{
    float average_temp;
    int denum;
    int ind;
    ind = 0;
    denum = 0;
    average_temp = 0.0;
    while (pst_month[ind].year > 0)
    {
        average_temp += pst_month[ind].average_temp_month;
        denum++;
        ind++;
    }
    average_temp = average_temp / (float) denum;
    p_year->year = pst_month->year;
    p_year->average_temp_year = average_temp;
}
void min_temp_year(out_stat_month_* pst_month,out_stat_year_* p_year)
{
    int ind;
    int8_t min_temp;
    ind = 0;
    min_temp = pst_month[ind++].min_temp_month;
    while (pst_month[ind].year > 0)
    {
        if (pst_month[ind].min_temp_month < min_temp)
        {
            min_temp = pst_month[ind].min_temp_month;
        }
        ind++;
    }
    p_year->year = pst_month->year;
    p_year->min_temp_year = min_temp;
}
void max_temp_year(out_stat_month_* pst_month,out_stat_year_* p_year)
{
    int ind;
    int8_t max_temp;
    ind = 0;
    max_temp = pst_month[ind++].max_temp_month;
    while (pst_month[ind].year > 0)
    {
        if (pst_month[ind].max_temp_month > max_temp)
        {
            max_temp = pst_month[ind].max_temp_month;
        }
        ind++;
    }
    p_year->year = pst_month->year;
    p_year->max_temp_year = max_temp;
}

