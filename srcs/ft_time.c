/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:53:26 by dgoubin           #+#    #+#             */
/*   Updated: 2023/06/19 13:54:43 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_actual_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long	timestamp(struct timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(int n)
{
	long	start;

	start = get_actual_time();
	while ((get_actual_time() - start) < n)
		usleep(n / 10);
}
