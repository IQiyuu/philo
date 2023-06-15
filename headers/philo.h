/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:42:54 by dgoubin           #+#    #+#             */
/*   Updated: 2023/06/15 16:48:43 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOKER
# define JOKER

    #include <stdio.h>
    #include <sys/time.h>
    #include <unistd.h>
    #include <pthread.h>
    #include <stdlib.h>

    # ifndef EXIT_FAILLURE
    #  define EXIT_FAILLURE 1
    # endif
    # ifndef EXIT_SUCCESS
    #  define EXIT_SUCCESS 0
    # endif

    typedef struct s_world {
        struct timeval  stime;
        int             pn;
        int             all_ate;
        int             ttd;
        int             tte;
        int             tts;
        int             en;
        int             ended;
        struct s_philo  *philos;
        pthread_mutex_t writing;
        pthread_mutex_t *forks;
        pthread_mutex_t death;
    } t_world;

    typedef struct  s_philo {
        int             id;
        int             eating_time;
        pthread_t       thread;
        t_world         *world;
        struct timeval  last_eat;
    } t_philo;

    void    init_all(t_world *world, char *av[], int ac);
    size_t  ft_strlen(char *str);
    void    error_handler(char *str);
    long    get_actual_time(struct timeval stime);
    long    timestamp(struct timeval time);
    int     ft_atoi(const char *str);
    void    launch(t_world *world);
    void    *philo_life(void *p);
    void    ft_usleep(int n);
#endif