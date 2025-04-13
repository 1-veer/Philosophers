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