/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 08:22:24 by npizzi            #+#    #+#             */
/*   Updated: 2024/10/31 11:44:32 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double complex	ft_atoc(char *str)
{
	double	i_part;
	double	r_part;
	int		i;
	int		sign;
	char	*img_part;

	sign = 1;
	i = 0;
	img_part = ft_strtod(str, &r_part);
	while (ft_isspace(img_part[i]) == true)
		i++;
	if (img_part[i] == '+' || img_part[i] == '-')
	{
		if (img_part[i] == '-')
			sign = -1;
		i++;
	}
	img_part = img_part + i;
	ft_strtod(img_part, &i_part);
	return (r_part + (sign * i_part * I));
}
