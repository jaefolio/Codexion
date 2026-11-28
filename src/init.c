/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/28 21:20:04 by jifoo             #+#    #+#             */
/*   Updated: 2026/11/28 23:01:18 by jifoo            ###   ########.fr       */
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