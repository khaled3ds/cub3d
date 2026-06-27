/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:19:37 by kadas             #+#    #+#             */
/*   Updated: 2025/08/09 09:33:57 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*r;
	size_t			t;

	r = (unsigned char *)s;
	t = 0;
	while (t < n)
	{
		if (r[t] == (unsigned char)c)
			return ((void *)&r[t]);
		t++;
	}
	return (NULL);
}
