/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:47:01 by dgoubin           #+#    #+#             */
/*   Updated: 2023/06/19 13:52:48 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	msg_write(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->world->writing);
	printf("%ld ms - philo %d %s\n", get_actual_time() - philo->world->stime,
		philo->id, str);
	pthread_mutex_unlock(&philo->world->writing);
}

static void	end_checker(t_philo *philo)
{
	pthread_mutex_lock(&philo->world->death);
	if (philo->world->ended)
		pthread_exit(NULL);
	pthread_mutex_unlock(&philo->world->death);
}

static void	philo_sleep(t_philo *philo)
{
	msg_write(philo, "is sleeping");
	end_checker(philo);
	ft_usleep(philo->world->tts);
}

static void	philo_eat(t_philo *philo)
{
	int	c;

	c = philo->id;
	if (philo->id == philo->world->pn)
		c = 0;
	pthread_mutex_lock(&philo->world->forks[philo->id - 1]);
	end_checker(philo);
	msg_write(philo, "has taken a fork");
	pthread_mutex_lock(&philo->world->forks[c]);
	end_checker(philo);
	msg_write(philo, "has taken a fork");
	msg_write(philo, "is eating");
	philo->eating_time++;
	end_checker(philo);
	gettimeofday(&philo->last_eat, NULL);
	ft_usleep(philo->world->tte);
	pthread_mutex_unlock(&philo->world->forks[philo->id - 1]);
	pthread_mutex_unlock(&philo->world->forks[c]);
}

void	*philo_life(void *p)
{
	t_philo	*philo;

	philo = p;
	if (philo->id % 2 == 0)
		usleep(300);
	while (1)
	{
		end_checker(philo);
		philo_eat(philo);
		if (philo->eating_time == philo->world->en)
		{
			philo->world->all_ate++;
			pthread_exit(NULL);
		}
		end_checker(philo);
		philo_sleep(philo);
	}
	return (NULL);
}
