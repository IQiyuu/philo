/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:47:18 by dgoubin           #+#    #+#             */
/*   Updated: 2023/06/19 13:53:57 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_mutex(t_world *world)
{
	int	i;

	i = 0;
	world->forks = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * world->pn);
	while (i < world->pn)
	{
		pthread_mutex_init(&world->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&world->writing, NULL);
	pthread_mutex_init(&world->death, NULL);
}

static void	init_philo(t_world *world)
{
	int	i;

	world->philos = (t_philo *)malloc(sizeof(t_philo) * world->pn);
	if (!world->philos)
		error_handler("philo number unvailable\n");
	i = 0;
	while (i < world->pn)
	{
		world->philos[i].id = i + 1;
		world->philos[i].eating_time = 0;
		world->philos[i].world = world;
		i++;
	}
}

void	init_all(t_world *world, char *av[], int ac)
{
	world->pn = ft_atoi(av[1]);
	if (world->pn < 1)
		error_handler("philo number unvailable\n");
	world->ttd = ft_atoi(av[2]);
	if (world->ttd < 0)
		error_handler("time to die unvailable\n");
	world->tte = ft_atoi(av[3]);
	if (world->tte < 1)
		error_handler("time to eat unvailable\n");
	world->tts = ft_atoi(av[4]);
	if (world->pn < 1)
		error_handler("time to sleep unvailable\n");
	world->en = -1;
	if (ac == 6)
		world->en = ft_atoi(av[5]);
	world->all_ate = 0;
	world->ended = 0;
	init_mutex(world);
	init_philo(world);
}
