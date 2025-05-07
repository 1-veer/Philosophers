#include "philo.h"

long	ft_atol(char *str)
{
	long	result;
	int		sign;
	int		i;

	// if (!str || !*str)
	// 	return (0);
	result = 0;
	sign = 1;
	i = 0;
	
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (0);
	}
	return (result * sign);
}

void init_container(my_container *container, char **argv)
{
	if (!argv || !*argv)
		return ;

	container->number_of_philosophers = ft_atol(argv[1]);
	container->time_to_die = ft_atol(argv[2]);
	container->time_to_eat = ft_atol(argv[3]);
	container->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		container->number_of_times_each_philosopher_must_eat = ft_atol(argv[5]);
	else
		container->number_of_times_each_philosopher_must_eat = -1;

}

int fix_args (my_container *container)
{
	if (container->number_of_philosophers <= 0 
		|| container->number_of_philosophers > 200)
		return	(1);
	else if (container->time_to_die < 60 
			|| container->time_to_eat < 60
			|| container->time_to_sleep < 60)
		return (1);
	//limit high values
	else if (container->number_of_times_each_philosopher_must_eat != -1 && 
		( container->number_of_times_each_philosopher_must_eat <= 0
			|| container->number_of_times_each_philosopher_must_eat > 200))
	return (1);

	return (0);
}

int parsing(my_container *container , char **argv)
{
	init_container(container, argv);
	
	if (fix_args(container))
		return (1);
	
	return (0);
}








 
