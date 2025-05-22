/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:01:59 by ayoub             #+#    #+#             */
/*   Updated: 2025/05/22 15:47:31 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_message(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

long	gettime(void)
{
	struct timeval	time;
	long			time_in_ms;

	gettimeofday(&time, NULL);
	time_in_ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (time_in_ms);
}

void	*allocate(size_t size, t_container *container)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		error_message("malloc error");
		doing_dishes(container);
		return (NULL);
	}
	return (ptr);
}

void	my_usleep(long time, t_container *container)
{
	long	t;

	t = gettime();
	while (1)
	{
		if (gettime() - t >= time)
			break ;
		if (checks(container))
			break ;
		usleep(100);
	}
}

void	printing(t_philo *philo, char *str)
{
	long	time;

	if (checks(philo->container))
		return ;
	time = gettime() - philo->container->start;
	printf("%ld %d %s\n", time, philo->philo_id, str);
}
