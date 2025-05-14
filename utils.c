#include "philo.h"

void error_message(char *str)
{
    int i = 0;
    while (str[i])
    {
        write(2, &str[i], 1);
        i++;
    }
    write(2, "\n", 1);
    exit(EXIT_FAILURE);
}

long get_time(void)
{
    struct timeval time;
    long time_in_ms;

      
    time_in_ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
    return (time_in_ms);
}
