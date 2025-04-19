#include "philo.h"

void error (char *str)
{
    int i = 0;
    while (str[i])
    {
        write (1, &str[i], 1);
        i++;
    }
    write (1, "\n", 1);
}

long get_time(void)
{
    struct timeval time;
    long time_in_ms;

    gettimeofday(&time, NULL);
    time_in_ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
    return (time_in_ms);
}
