/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 08:16:04 by npizzi            #+#    #+#             */
/*   Updated: 2024/10/31 11:27:02 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtod(char *str, double *atod)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	*atod = ft_atoi(str);
	while (ft_isspace(str[i]) == true)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		i++;
		*atod = *atod + (sign) * (float)ft_atoi(str + i) / ft_pow(10,
				ft_numlen(ft_atoi(str + i)));
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	return (str + i);
}
