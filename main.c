#include "philo.h"
//#include <stdio.h>


	int main(int ac, char *av[])
	{
		t_container my_container;
	
		if (ac != 5 && ac != 6)
			error_message("usage_error");
		if (parsing(&my_container, av))
			error_message("values_error");	

		having_seats(&my_container );
		dinner(&my_container);
		doing_dishes(&my_container);

		return (EXIT_SUCCESS);
	}
	
