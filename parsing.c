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

void put_input (my_container *container, char **argv)
{
	if (!argv || !*argv)
		return ;

	container->num_of_philos = ft_atol(argv[1]);
	container->time_to_die = ft_atol(argv[2]) * 1000;
	container->time_to_eat = ft_atol(argv[3]) * 1000;
	container->time_to_sleep = ft_atol(argv[4]) * 1000;
	if (argv[5])
		container->num_must_eat = ft_atol(argv[5]) ;
	else
		container->num_must_eat = -1;

}

int check_input (my_container *container)
{
	if (container->num_of_philos <= 0 
		|| container->num_of_philos > 200)
		return	(1);
	else if (container->time_to_die < 60000 
			|| container->time_to_eat < 60000
			|| container->time_to_sleep < 60000)
		return (1);
	//limit high values
	else if (container->num_must_eat != -1 && 
		( container->num_must_eat <= 0
			|| container->num_must_eat > 200))
	return (1);

	return (0);
}

int parsing(my_container *container , char **argv)
{
	put_input(container, argv);
	
	if (check_input(container))
		return (1);
	
	return (0);
}








 
