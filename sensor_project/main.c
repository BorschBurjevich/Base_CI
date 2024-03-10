#include "temp_api.h"
sensor_info_ sensor_inf[SIZE_INF];
out_stat_month_ sensor_stat_month[SIZE_INF];
out_stat_year_ sensor_stat_year;

int main(int argc, char* argv[])
{
    int ind,num_month;
    FILE *open_f;
    int get_arg = 0;
    int r = 0;
    char ch = 0;
    int cntr = 0;
    ind = 0;
    num_month = 0;
    if (argc == 1)
    {
        info_app();
    }
    memset(&sensor_inf,0x0,sizeof(sensor_inf));
    memset(&sensor_stat_month,0x0,sizeof(sensor_stat_month));
    memset(&sensor_stat_year,0x0,sizeof(sensor_stat_year));
    /////////////////////////////////////////////////////////////////

    while ((get_arg = getopt(argc,argv,"hf:m:td")) != -1)
    {
        switch (get_arg)
        {
            case 'h':
                puts("-f <filename.csv>: Get input data temperature;");
                puts("-m <month number>: Get  statistic of the month, use with -f;");
                puts("-t : Sort data by temperature, use with -f ;");
                puts("-d : Sort data by date, use with -f;");
                break;
            case 'f':
                printf("Name of <csv> file is \"%s\" \n",optarg);
                open_f = fopen(optarg, "r");
                if (open_f == NULL)
                { 
                    fclose(open_f);
                    printf("Can't open your file: %s\n",optarg);
                    return 1;
                   
                }   
                while ((r = fscanf(open_f,"%d;%d;%d;%d;%d;%d",&sensor_inf[ind].year,&sensor_inf[ind].month,&sensor_inf[ind].day,&sensor_inf[ind].hh,&sensor_inf[ind].mm,&sensor_inf[ind].t))>0)
                {
                    cntr++;
                    if (r < MAX_NUM)
                    {
                        do 
                        {
                            putchar(ch);
                            ch = fgetc(open_f);
                        } while (EOF != ch && '\n'!=ch);
                        ch = 0;
                        printf("Format error in line: %d\n",cntr);
                        ind--;   
                    }
                    else
                    {
                        ind++;
                    }
                }
                fclose(open_f);
                average_temp_month(sensor_inf,ind,sensor_stat_month);
                min_temp_month(sensor_inf,ind,sensor_stat_month);
                max_temp_month(sensor_inf,ind,sensor_stat_month);
                average_temp_year(sensor_stat_month,&sensor_stat_year);
                min_temp_year(sensor_stat_month,&sensor_stat_year);
                max_temp_year(sensor_stat_month,&sensor_stat_year);
                if(!argv[3])
                {
                    print_out_stat_month(sensor_stat_month);
                    print_out_stat_year(&sensor_stat_year);
                }
                break;
            case 'm':
                printf("Number of month is %d\n",atoi(optarg));
                num_month = atoi(optarg);
                if(print_out_stat_this_month(sensor_stat_month,num_month))
                {
                    printf("Cant find inf for month:%d\n",num_month);
                    return 1;
                }
                break;
            case 't':
                sort_by_temp(sensor_inf,ind);
                print_sensor (sensor_inf,ind);
                break;

            case 'd':
                sort_by_date(sensor_inf,ind);
                print_sensor (sensor_inf,ind);
                break;
            default:
                break;
        }
    }
    return 0;
}