/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:02:34 by ayoub             #+#    #+#             */
/*   Updated: 2025/05/20 20:05:13 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	one_philo_case(t_philo *philo)
{
	printing(philo, "has taken a fork");
	my_usleep(philo->container->time_to_die);
	printing(philo, "died");
}

void	*simulation(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->container->num_of_philos == 1)
	{
		one_philo_case(philo);
		return (NULL);
	}
	while (true)
	{
		eat(philo);
		s_leep(philo);
		think(philo);
		if (checks(philo->container))
			break ;
	}
	return (NULL);
}

int	scanning(t_container *container, int n)
{
	long	t;

	pthread_mutex_lock(container->mutexes->time_mtx);
	t = gettime() - container->philo[n].last_meal_time;
	pthread_mutex_unlock(container->mutexes->time_mtx);
	if (container->time_to_die < t)
	{
		pthread_mutex_lock(container->mutexes->print_mtx);
		printing(&container->philo[n], "died");
		pthread_mutex_unlock(container->mutexes->print_mtx);
		pthread_mutex_lock(container->mutexes->dead_mtx);
		container->is_dead = true;
		pthread_mutex_unlock(container->mutexes->dead_mtx);
		return (1);
	}
	return (0);
}

void	*monitor(void *ptr)
{
	t_container	*container;
	int			i;

	container = (t_container *)ptr;
	if (container->num_of_philos == 1)
		return (NULL);
	i = 0;
	while (true)
	{
		if (done_eating(container))
			return (NULL);
		if (i >= container->num_of_philos)
			i = 0;
		if (scanning(container, i))
			return (NULL);
		i++;
		my_usleep(1);
	}
	return (NULL);
}

void	dinner(t_container *container)
{
	int			i;
	int			n;
	pthread_t	my_monitor;

	n = container->num_of_philos;
	i = 0;
	pthread_create(&my_monitor, NULL, &monitor, container);
	container->start = gettime();
	while (i < n)
	{
		pthread_create(&container->philo[i].thread_id, NULL,
			&simulation, &container->philo[i]);
		i++;
	}
	i = 0;
	while (i < n)
	{
		pthread_join(container->philo[i].thread_id, NULL);
		i++;
	}
	pthread_join(my_monitor, NULL);
}
