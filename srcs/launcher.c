/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:08:55 by dgoubin           #+#    #+#             */
/*   Updated: 2023/06/19 13:53:25 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	launch(t_world *world)
{
	int				i;
	struct timeval	stime;

	i = 0;
	gettimeofday(&stime, NULL);
	world->stime = timestamp(stime);
	while (i < world->pn)
	{
		gettimeofday(&world->philos[i].last_eat, NULL);
		pthread_create(&world->philos[i].thread, NULL,
			philo_life, &world->philos[i]);
		i++;
	}
}
