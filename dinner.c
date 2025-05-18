#include "philo.h"

void    one_philo_case(t_philo *philo)
{
    printing(philo, "took a fork");
    my_usleep(philo->container->time_to_die);
    printing(philo, "died");
}

void *simulation(void *arg)
{
    t_philo *philo;
    philo = (t_philo *)arg;
    if (philo->container->num_of_philos == 1)
    {
        one_philo_case(philo);
        return (NULL);
    }
    while (1)
    {
        eat(philo),s_leep(philo),think(philo);
        if(checks(philo))
            break ;
    }
    return (NULL);
}
void *dinner(t_container *container)
{
    int i;
    int n;
    pthread_t *my_monitor;

    n = container->num_of_philos;
    i = 0;
    pthread_create(&my_monitor, NULL, simulation, container);
    while (i < n)
    {
        pthread_create(&container->philo[i].thread_id, NULL, simulation, &container->philo[i]);
        i++;
    }
    i = 0;
    while (i < n)
    {
        pthread_join(container->philo[i].thread_id, NULL);
        i++;
    }
    pthread_join(my_monitor, NULL);
    return (NULL);
}



