/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/28 17:13:54 by jifoo             #+#    #+#             */
/*   Updated: 2026/11/28 22:45:45 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int main(int argc, char **argv)
{
    t_params params;
    t_hub    hub;
    
    if (argc != 9)
        return raise_error("Invalid number of arguments!");
    if(parse_input(&hub, &params, argv + 1))
        return (1);
    init_hub(&hub, &params);
    cleanup_hub(&hub, &params);
    return (0);
}