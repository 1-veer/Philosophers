/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:02:13 by ayoub             #+#    #+#             */
/*   Updated: 2025/05/22 16:19:29 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	t_container	*container;

	container = philo->container;
	if (checks(container))
		return ;
	if (philo->philo_id % 2 != 0)
		my_usleep(5, container);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(container->mutexes->print_mtx);
	printing(philo, "has taken a fork");
	printing(philo, "has taken a fork");
	printing(philo, "is eating");
	pthread_mutex_unlock(container->mutexes->print_mtx);
	pthread_mutex_lock(container->mutexes->time_mtx);
	philo->last_meal_time = gettime();
	pthread_mutex_unlock(container->mutexes->time_mtx);
	pthread_mutex_lock(container->mutexes->meals_mtx);
	philo->meal_counter += 1;
	pthread_mutex_unlock(container->mutexes->meals_mtx);
	my_usleep(container->time_to_eat, container);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	s_leep(t_philo *philo)
{
	t_container	*container;

	container = philo->container;
	if (checks(container))
		return ;
	pthread_mutex_lock(container->mutexes->print_mtx);
	printing(philo, "is sleeping");
	pthread_mutex_unlock(container->mutexes->print_mtx);
	my_usleep(container->time_to_sleep, container);
}

void	think(t_philo *philo)
{
	t_container	*container;

	container = philo->container;
	if (checks(container))
		return ;
	pthread_mutex_lock(container->mutexes->print_mtx);
	printing(philo, "is thinking");
	pthread_mutex_unlock(container->mutexes->print_mtx);
}
