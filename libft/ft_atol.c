/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:29:49 by nicco             #+#    #+#             */
/*   Updated: 2024/10/31 11:41:07 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

long	ft_atol(const char *nptr)
{
	long	atol;
	int		i;
	int		sign;

	atol = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(nptr[i]) == true)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		if (nptr[i + 1] == '+' || nptr[i + 1] == '-')
			return (0);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		atol = (atol * 10) + (nptr[i] - 48);
		i++;
	}
	return (atol * sign);
}
