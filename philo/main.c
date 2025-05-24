/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougati <abougati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:02:06 by ayoub             #+#    #+#             */
/*   Updated: 2025/05/24 15:26:15 by abougati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_container	my_container;

	if (parsing(&my_container, ac, av))
		if (!(error_message("values_error")))
			return (1);
	having_seats(&my_container);
	dinner(&my_container);
	doing_dishes(&my_container);
	return (0);
}
