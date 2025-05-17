#include "philo.h"

void forks_init(t_container *container)
{
    int i;
    
    container->fork = allocate(sizeof(mutex) * container->num_of_philos);
    i = 0;
    while (i < container->num_of_philos)
    {
        pthread_mutex_init(&container->fork[i], NULL);
        i++;
    }
}

void mutex_init(t_container *container)
{
    container->mutex->print_mtx = allocate(sizeof(mutex));
    container->mutex->time_mtx = allocate(sizeof(mutex));
    container->mutex->meals_mtx = allocate(sizeof(mutex));
    container->mutex->dead_mtx = allocate(sizeof(mutex));
    container->mutex->done_mtx = allocate(sizeof(mutex));
    pthread_mutex_init(container->mutex->print_mtx, NULL);
    pthread_mutex_init(container->mutex->time_mtx, NULL);
    pthread_mutex_init(container->mutex->meals_mtx, NULL);
    pthread_mutex_init(container->mutex->dead_mtx, NULL);
    pthread_mutex_init(container->mutex->done_mtx, NULL);
}

void philos_init(t_container *container)
{
    t_philo *tmp_philo;
    int i;
    
    i = 0;
    tmp_philo = allocate(sizeof(t_philo) * container->num_of_philos);
    while(i < container->num_of_philos)
    {
        tmp_philo[i].philo_id = i+1;
        tmp_philo[i].thread_id = 0;
        tmp_philo[i].meal_counter = 0;
        tmp_philo[i].last_meal_time = gettime();
        tmp_philo[i].container = container;
        if (container->num_of_philos > 1)
        get_forks(&tmp_philo[i], container, i);
        i++;
    }
    container->philo = tmp_philo;
}

void get_forks (t_philo *philo, t_container *container, int position)
{
    int n;
    
    n = container->num_of_philos;
    if (philo->philo_id % 2 != 0) // if odd
    {
        philo->right_fork = &container->fork[(position + 1) % n];
        philo->left_fork = &container->fork[position];
    }
    else // if even
    {
        philo->right_fork = &container->fork[position];
        philo->left_fork = &container->fork[(position + 1) % n];
    }
}

void having_seats(t_container *my_container)
{
    my_container->dead = false;
    my_container->done_eating = false;
    my_container->start = gettime();
    my_container->mutex = allocate(sizeof(t_mutex));
    forks_init(my_container);
    mutex_init(my_container);
    philos_init(my_container);
}