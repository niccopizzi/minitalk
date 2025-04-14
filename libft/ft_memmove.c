/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:08:52 by npizzi            #+#    #+#             */
/*   Updated: 2024/10/31 11:28:39 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*s1;
	const char	*s2;

	s1 = dest;
	s2 = src;
	if (src == NULL && dest == NULL)
		return (NULL);
	if (src < dest && (src + n) >= dest)
	{
		while (n > 0)
		{
			s1[(n - 1)] = s2[(n - 1)];
			n--;
		}
	}
	else
		dest = ft_memcpy(dest, src, n);
	return (dest);
}
