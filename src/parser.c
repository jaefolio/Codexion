/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/28 17:11:10 by jifoo             #+#    #+#             */
/*   Updated: 2026/11/28 18:36:17 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int validate_input(t_params *params)
{
    if (params->nb_coders <= 0)
        return((raise_error("Invalid coders value")));
    if (params->time_to_burnout <= 0)
        return((raise_error("Invalid time to burnout value")));
    if (params->time_to_compute <= 0)
    return((raise_error("Invalid time to compute value")));
        if (params->time_to_debug <= 0)
    return((raise_error("Invalid time to debug value")));
        if (params->time_to_refactor <= 0)
    return((raise_error("Invalid time to refactor value")));
        if (params->nb_compiles_required <= 0)
    return((raise_error("Invalid number of compiles required value")));
        if (params->dongle_cooldown <= 0)
    return((raise_error("Invalid dongle cooldown value")));
        if (strcmp("fifo", params->scheduler) != 0 &&
    strcmp("edf", params->scheduler) != 0)
        return((raise_error("Invalid scheduler type")));
    return (0);
    
}

int parse_input(t_params *params, char **args)
{
    params->nb_coders = ft_atol(args[0]);
    params->time_to_burnout = ft_atol(args[1]) ;
    params->time_to_compute = ft_atol(args[2]);
    params->time_to_debug = ft_atol(args[3]);
    params->time_to_refactor = ft_atol(args[4]);
    params->nb_compiles_required = ft_atol(args[5]);
    params->dongle_cooldown = ft_atol(args[6]);
    params->scheduler = args[7];
    /*pas oublier de retirer*/
    printf("%ld\n", params->nb_coders);
    printf("%ld\n", params->time_to_burnout);
    printf("%ld\n", params->time_to_compute);
    printf("%ld\n", params->time_to_debug);
    printf("%ld\n", params->time_to_refactor);
    printf("%ld\n", params->nb_compiles_required);
    printf("%ld\n", params->dongle_cooldown);
    printf("%s\n", params->scheduler);
    if (!validate_input(params))
        return (0);
    return (1);
}