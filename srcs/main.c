/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:42:06 by dgoubin           #+#    #+#             */
/*   Updated: 2023/06/19 13:53:05 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_world	world;

	if (ac < 5 || ac > 6)
		error_handler("Arg number\n");
	init_all(&world, av, ac);
	launch(&world);
	usleep(100);
	checker(&world);
	return (EXIT_SUCCESS);
}
