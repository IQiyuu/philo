/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:06:08 by dgoubin           #+#    #+#             */
/*   Updated: 2023/06/15 14:11:49 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    error_handler(char *str)
{
    if (!str)
        return ;
    write(2, str, ft_strlen(str));
    exit(EXIT_FAILLURE);
}