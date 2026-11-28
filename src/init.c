/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/28 21:20:04 by jifoo             #+#    #+#             */
/*   Updated: 2026/11/28 23:47:04 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int init_hub(t_hub *hub, t_params *params)
{
    hub->coders = NULL;
    hub->dongles = NULL;
    hub->params = *params;
    
    hub->coders = malloc(sizeof(t_coder) * params->nb_coders);
    hub->dongles = malloc(sizeof(t_dongle) * params->nb_coders);
    if (!hub->coders || !hub->dongles)
    {
        cleanup_hub(hub, params);
        return (1);
    }
    init_coders(hub, params);
    init_dongles(hub, params);
    return(0);
}

void    cleanup_hub(t_hub *hub, t_params *params)
{
    if (!hub || !params)
        return ;
    if (hub->coders)
        free(hub->coders);
    if (hub->dongles)
        free(hub->dongles);
    hub->coders = NULL;
    hub->dongles = NULL;
}

int init_coders(t_hub *hub, t_params *params)
{
    int i;

    i = 0;
    while (i < params->nb_coders)
    {
        hub->coders[i].id = i + 1;
        hub->coders[i].n_compiles = 0;
        hub->coders[i].last_compile_start = 0;
        printf("coder id: %d\n", hub->coders[i].id);
        printf("n compiles: %ld\n", hub->coders[i].n_compiles);
        printf("last compile start: %ld\n", hub->coders[i].last_compile_start);
        i++;
    }
    return (0);
}

int init_dongles(t_hub *hub, t_params *params)
{
    int i;

    i = 0;
    while (i < params->nb_coders)
    {
        hub->dongles[i].id = i + 1;
        printf("dongle id: %d\n", hub->dongles[i].id);
        i++;
    }
    return (0);
}