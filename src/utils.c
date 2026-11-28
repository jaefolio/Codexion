/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/28 17:13:06 by jifoo             #+#    #+#             */
/*   Updated: 2026/11/28 18:29:17 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int raise_error(char *str)
{
    printf("[ERROR] %s\n", str);
    return (1);
}

static long is_num(long value, char *str)
{
    while (*str)
    {
        if (!(*str >= '0' && *str <= '9'))
            return (-1);
        str++;
    }
    return (value);
}

long    ft_atol(char *str)
{
    int i;
    int sign;
    long res;
    
    i = 0;
    sign = 1;
    res = 0;
    while (str[i] == ' ' && (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        if (res > (LONG_MAX - (str[i] - '0')) / 10)
			return (-1);
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (is_num(res * sign, str));
}
