/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 19:10:06 by kadas             #+#    #+#             */
/*   Updated: 2025/08/10 21:19:57 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s2len;
	size_t	i;
	char	*c;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	s2len = ft_strlen(s2);
	c = malloc(ft_strlen(s1) + s2len + 1);
	if (!c)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		c[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2len)
	{
		c[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	c[ft_strlen(s1) + s2len] = '\0';
	return (c);
}
