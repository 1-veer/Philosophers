#include "philo.h"
#include <stdio.h>


	int main(int ac, char *av[])
	{
		my_container my_container;
	
		if (ac != 5 && ac != 6)
		{
			error("usage_error");
			return (1);
		}
	
		if (parsing(&my_container, av))
		{
			error("values_error");
			return (1);
		}
		//inint (&my_container);
		//simulation (&my_container);
		//clean_up;
	
		printf("Time to die: %ld\n", my_container.time_to_die);
		printf("Time to eat: %ld\n", my_container.time_to_eat);
		printf("Time to sleep: %ld\n", my_container.time_to_sleep);
		printf("Number of philosophers: %ld\n", my_container.number_of_philosophers);
		if (ac == 6)
			printf("Number of times each philosopher must eat: %ld\n", my_container.number_of_times_each_philosopher_must_eat);
	
		return (0);
	}
	