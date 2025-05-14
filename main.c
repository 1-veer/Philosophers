#include "philo.h"
//#include <stdio.h>


	int main(int ac, char *av[])
	{
		my_container container;
	
		if (ac != 5 && ac != 6)
			error_message("usage_error");
	
		if (parsing(&container, av))
			error_message("values_error");	

		//init
		//simulation (&my_container);
		//clean_up;
	
		// printf("Time to die: %ld\n", container.time_to_die);
		// printf("Time to eat: %ld\n", container.time_to_eat);
		// printf("Time to sleep: %ld\n", container.time_to_sleep);
		// printf("Number of philosophers: %ld\n", container.number_of_philosophers);
		// if (ac == 6)
		// 	printf("Number of times each philosopher must eat: %ld\n", container.number_of_times_each_philosopher_must_eat);
	
		return (0);
	}
	
