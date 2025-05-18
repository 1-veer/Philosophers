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

long gettime(void)
{
    struct timeval time;
    long time_in_ms;

    gettimeofday(&time, NULL);
    time_in_ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
    return (time_in_ms);
}

void *allocate(size_t size)
{
    void *ptr;
// might add the container as a parameter so that we can free here 
    ptr = malloc(size);
    if (!ptr)
        error_message("malloc error");
    return (ptr);
}
void my_usleep(long time)
{
    long t;

    t = gettime();
    while (1)
    {
        if (gettime() - t >= time)
            break;
        usleep(100);
    }
}

void printing(t_philo *philo, char *str)
{
    long time;
    
    time = gettime() - philo->container->start;
    printf("after %ldms --> philo'%d' %s\n", time, philo->philo_id, str);
}