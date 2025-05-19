#include "philo.h"

int dead(t_container *container)
{
    pthread_mutex_lock(container->mutexes->dead_mtx);
    if (container->is_dead)
    {
        container->is_dead = false;
        pthread_mutex_unlock(container->mutexes->dead_mtx);
        return (1);
    }
    pthread_mutex_unlock(container->mutexes->dead_mtx);
    return (0);
}

int done_eating(t_container *container)
{
    int i;
    int done;

    i = 0;
    done = 0;
    pthread_mutex_lock(container->mutexes->done_mtx);
    pthread_mutex_lock(container->mutexes->meals_mtx);
    while (i < container->num_of_philos)
    {
        if (container->philo[i].meal_counter >= container->num_must_eat)
            done++;
        i++;
    }
    if (done == container->num_of_philos && container->num_must_eat != -1)
       {
        container->done_eating = true; // might be useless
        pthread_mutex_unlock(container->mutexes->done_mtx);
        pthread_mutex_unlock(container->mutexes->meals_mtx);
        return (1);
       } 
    pthread_mutex_unlock(container->mutexes->done_mtx);
    pthread_mutex_unlock(container->mutexes->meals_mtx);
    return (0);
}

int checks(t_container *container)
{
    if (dead(container) || done_eating(container))
        return (1);
    else 
        return (0);
}