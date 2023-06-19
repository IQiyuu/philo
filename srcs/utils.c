/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:06:54 by dgoubin           #+#    #+#             */
/*   Updated: 2023/06/19 13:48:02 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		;
	return (i - 1);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	minus;

	res = 0;
	minus = 1;
	while (*str == 32 || *str == 9 || *str == 10 || *str == 12 || *str == 13
		|| *str == 11)
		str++;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			minus = -1;
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + *(str++) - '0';
	return (res * minus);
}
