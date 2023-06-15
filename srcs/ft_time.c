/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:53:26 by dgoubin           #+#    #+#             */
/*   Updated: 2023/06/15 16:28:44 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long    timestamp(struct timeval time)
{
        return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long    get_actual_time(struct timeval stime)
{
        struct timeval  at;

        gettimeofday(&at, NULL);
        return (timestamp(at) - timestamp(stime));
}

void    ft_usleep(int n)
{
        struct timeval  start;

        gettimeofday(&start, NULL);
        while (1)
                if (get_actual_time(start) >= n)
                        break ;
}
