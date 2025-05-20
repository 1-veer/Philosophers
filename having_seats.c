/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   having_seats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:02:10 by ayoub             #+#    #+#             */
/*   Updated: 2025/05/20 19:17:55 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks_init(t_container *container)
{
	int	i;

	container->fork = allocate(sizeof(t_m)
			* container->num_of_philos, container);
	i = 0;
	while (i < container->num_of_philos)
	{
		pthread_mutex_init(&container->fork[i], NULL);
		i++;
	}
}

void	mutex_init(t_container *container)
{
	container->mutexes->print_mtx = allocate(sizeof(t_m), container);
	container->mutexes->time_mtx = allocate(sizeof(t_m), container);
	container->mutexes->meals_mtx = allocate(sizeof(t_m), container);
	container->mutexes->dead_mtx = allocate(sizeof(t_m), container);
	container->mutexes->done_mtx = allocate(sizeof(t_m), container);
	pthread_mutex_init(container->mutexes->print_mtx, NULL);
	pthread_mutex_init(container->mutexes->time_mtx, NULL);
	pthread_mutex_init(container->mutexes->meals_mtx, NULL);
	pthread_mutex_init(container->mutexes->dead_mtx, NULL);
	pthread_mutex_init(container->mutexes->done_mtx, NULL);
}

void	philos_init(t_container *container)
{
	t_philo	*tmp_philo;
	int		i;

	i = 0;
	tmp_philo = allocate(sizeof(t_philo) * container->num_of_philos, container);
	while (i < container->num_of_philos)
	{
		tmp_philo[i].philo_id = i + 1;
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

void	get_forks(t_philo *philo, t_container *container, int position)
{
	int	n;

	n = container->num_of_philos;
	if (philo->philo_id % 2 != 0)
	{
		philo->right_fork = &container->fork[(position + 1) % n];
		philo->left_fork = &container->fork[position];
	}
	else
	{
		philo->right_fork = &container->fork[position];
		philo->left_fork = &container->fork[(position + 1) % n];
	}
}

void	having_seats(t_container *my_container)
{
	my_container->is_dead = false;
	my_container->done_eating = false;
	my_container->start = gettime();
	my_container->mutexes = allocate(sizeof(t_mtx), my_container);
	forks_init(my_container);
	mutex_init(my_container);
	philos_init(my_container);
}
