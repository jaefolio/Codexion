/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/28 17:13:54 by jifoo             #+#    #+#             */
/*   Updated: 2026/11/28 18:15:07 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int main(int argc, char **argv)
{
    t_params params;
    
    if (argc != 9)
        return raise_error("Invalid number of arguments!");
    parse_input(&params, argv + 1);
    return (0);
}