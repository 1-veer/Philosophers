/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:02:06 by ayoub             #+#    #+#             */
/*   Updated: 2025/05/20 19:13:17 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_container	my_container;

	if (parsing(&my_container, ac, av))
		error_message("values_error");
	having_seats(&my_container);
	dinner(&my_container);
	doing_dishes(&my_container);
	return (EXIT_SUCCESS);
}
