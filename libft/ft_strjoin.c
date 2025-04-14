/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:35:55 by nicco             #+#    #+#             */
/*   Updated: 2024/10/31 11:37:56 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	make_copy(char *new_str, char const *s1, char const *s2)
{
	int	i;
	int	x;

	i = 0;
	while (s1 != NULL && s1[i] != 0)
	{
		new_str[i] = s1[i];
		i++;
	}
	x = 0;
	while (s2 != NULL && s2[x] != 0)
	{
		new_str[i + x] = s2[x];
		x++;
	}
	new_str[i + x] = 0;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	new_str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
			* sizeof(char));
	if (new_str == NULL)
		return (NULL);
	make_copy(new_str, s1, s2);
	return (new_str);
}
