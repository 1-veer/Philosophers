/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:01:55 by ayoub             #+#    #+#             */
/*   Updated: 2025/05/24 19:22:32 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_container	t_container;
typedef pthread_mutex_t		t_m;

typedef struct s_mtx
{
	t_m	*print_mtx;
	t_m	*time_mtx;
	t_m	*meals_mtx;
	t_m	*dead_mtx;
}	t_mtx;

typedef struct s_philo
{
	t_container		*container;
	int				philo_id;
	pthread_t		thread_id;
	long			meal_counter;
	long			last_meal_time;
	t_m				*right_fork;
	t_m				*left_fork;
}	t_philo;

struct s_container
{
	long		num_of_philos;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		num_must_eat;
	bool		is_dead;
	long		start;
	t_m			*fork;
	t_mtx		*mutexes;
	t_philo		*philo;
};

void	init_container(t_container *my_container);
void	*error_message(char *str);
int		parsing(t_container *container, int ac, char **av);

void	having_seats(t_container *my_container);
void	dinner(t_container *container);
void	doing_dishes(t_container *container);

void	my_usleep(long time, t_container *container);
void	printing(t_philo *philo, char *str);
void	*allocate(size_t size, t_container *container);
long	gettime(void);
void	get_forks(t_philo *philo, t_container *container, int position);

void	eat(t_philo *philo);
void	s_leep(t_philo *philo);
void	think(t_philo *philo);

int		checks(t_container *container);
int		dead(t_container *container);
int		done_eating(t_container *container);

void	*monitor(void *ptr);

#endif
