#include "philo.h"


void destroy_mtx_struct(t_container *container)
{
    if (!container || !container->mutexes)
        return;
    pthread_mutex_destroy(container->mutexes->print_mtx);
    free(container->mutexes->print_mtx);
    pthread_mutex_destroy(container->mutexes->time_mtx);
    free(container->mutexes->time_mtx);
    pthread_mutex_destroy(container->mutexes->meals_mtx);
    free(container->mutexes->meals_mtx);
    pthread_mutex_destroy(container->mutexes->dead_mtx);
    free(container->mutexes->dead_mtx);
    pthread_mutex_destroy(container->mutexes->done_mtx);
    free(container->mutexes->done_mtx);
}
void doing_dishes(t_container *container)
{
    int i;
    if (!container)
        return;
    i = 0;
    while (i < container->num_of_philos)
    {
        pthread_mutex_destroy(&container->fork[i]);
        i++;
    }
    free(container->fork);
    destroy_mtx_struct(container);
    free(container->mutexes);
    free(container->philo);
}