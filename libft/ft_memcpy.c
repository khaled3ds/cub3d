/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:20:31 by kadas             #+#    #+#             */
/*   Updated: 2025/08/12 20:45:00 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*a;
	unsigned char		*b;
	size_t				i;

	a = (const unsigned char *)src;
	b = (unsigned char *)dest;
	if (!a && !b)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*b = *a;
		a++;
		b++;
		i++;
	}
	return (dest);
}
