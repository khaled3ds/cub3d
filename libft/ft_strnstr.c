/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:40:15 by kadas             #+#    #+#             */
/*   Updated: 2025/08/12 21:01:32 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l;
	size_t	n;
	size_t	little_len;

	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	l = 0;
	while (big[l] != '\0' && l + little_len <= len)
	{
		n = 0;
		while (n < little_len && big[l + n] == little[n])
			n++;
		if (n == little_len)
			return ((char *)&big[l]);
		l++;
	}
	return (NULL);
}
