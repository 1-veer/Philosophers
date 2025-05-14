#include "philo.h"


void get_forks (my_philo *philo , my_fork *fork , int position)
{
    int num_philos;

    num_philos = philo->container->num_of_philos;
    if (philo->philo_id % 2 != 0) // if odd
    {
        philo->right_fork = &fork[(position + 1) % num_philos];
        philo->left_fork = &fork[position];
    }
    else // if even
    {
        philo->right_fork = &fork[position];
        philo->left_fork = &fork[(position + 1) % num_philos];
    }
}

void init_philo (my_container *container)
{
    my_philo *philo;
    int i;

    i=0;
    while (i < container->num_of_philos)
    {
        philo = container->philo + i;
        philo->philo_id = i+1;
        philo->num_meals = 0;
        philo->done_eating = false;
        get_forks(philo, container->fork , i);
        philo-> container = container;
        // philo-> thread_id =
        i++;
    }
}

void init_container (my_container *container)
{
    container->end = false;
    container->philo = malloc(sizeof(my_container) * container->num_of_philos);
    if (!(container->philo))
        error_message("malloc error");
    container->fork = malloc(sizeof(my_fork) * container->num_of_philos);
    if (!(container->fork))
        error_message("malloc error");

    init_philo (container);
}