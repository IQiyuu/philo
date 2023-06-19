/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:47:09 by dgoubin           #+#    #+#             */
/*   Updated: 2023/06/19 13:55:27 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	checker(t_world *world)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < world->pn)
		{
			if (get_actual_time() - timestamp(world->philos[i].last_eat)
				> world->ttd
				&& world->philos[i].eating_time != world->en)
			{
				pthread_mutex_lock(&world->writing);
				printf("%ld ms - philo %d is dead\n", get_actual_time()
					- world->stime, i + 1);
				pthread_mutex_unlock(&world->writing);
				exit(EXIT_SUCCESS);
			}
			if (world->all_ate == world->pn)
				exit(EXIT_SUCCESS);
			i++;
		}
	}
}
