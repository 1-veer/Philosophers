#include "philo.h"

void *dinner(t_container *container)
{
    int i;
    int n;
    
    n = container->num_of_philos;
    i = 0;
    while (i < n)
    {
        pthread_create(&container->philo[i].thread_id, NULL, &simulation, &container->philo[i]);
        i++;
    }
    i = 0;
    while (i < n)
    {
        pthread_join(container->philo[i].thread_id, NULL);
        i++;
    }
    return (NULL);
}