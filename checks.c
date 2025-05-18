#include "philo.h"

int dead(t_container *container)
{
    pthread_mutex_lock(container->mutex->dead_mtx);
    if (container->dead)
    {
        container->dead = false;
        pthread_mutex_unlock(container->mutex->dead_mtx);
        return (1);
    }
    pthread_mutex_unlock(container->mutex->dead_mtx);
    return (0);
}

int done_eating(t_container *container)
{
    int i;
    int done;

    i = 0;
    done = 0;
    pthread_mutex_lock(container->mutex->done_mtx);
    pthread_mutex_lock(container->mutex->meals_mtx);
    while (i < container->num_of_philos)
    {
        if (container->philo[i].meal_counter >= container->num_must_eat)
            done++;
        i++;
    }
    if (done == container->num_of_philos)
       {
        container->done_eating = true;
        pthread_mutex_unlock(container->mutex->done_mtx);
        pthread_mutex_unlock(container->mutex->meals_mtx);
        return (1);
       } 
    pthread_mutex_unlock(container->mutex->done_mtx);
    pthread_mutex_unlock(container->mutex->meals_mtx);
    return (0);
}

int checks(t_container *container)
{
    if (dead(container) && done_eating(container))
        return (1);
    else 
        return (0);
}