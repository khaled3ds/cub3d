/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:37:03 by kadas             #+#    #+#             */
/*   Updated: 2025/08/10 21:05:37 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*a;
	unsigned char		*b;

	a = (const unsigned char *)src;
	b = (unsigned char *)dest;
	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
	{
		ft_memcpy(dest, src, n);
		return (dest);
	}
	else
	{
		while (n--)
			b[n] = a[n];
		return (dest);
	}
}
