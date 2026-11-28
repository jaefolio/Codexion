/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/28 17:00:18 by jifoo             #+#    #+#             */
/*   Updated: 2026/11/28 18:35:24 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

#include <pthread.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef struct s_params
{
    long nb_coders;
    long time_to_burnout;
    long time_to_compute;
    long time_to_debug;
    long time_to_refactor;
    long nb_compiles_required;
    long dongle_cooldown;
    char *scheduler;

}   t_params;

/*utils*/
int raise_error(char *str);
long    ft_atol(char *str);
/*parser*/
int validate_input(t_params *params);
int parse_input(t_params *params, char **args);

#endif