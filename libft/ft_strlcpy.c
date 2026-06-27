/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:46:45 by kadas             #+#    #+#             */
/*   Updated: 2025/08/09 09:34:39 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	temp;

	temp = 0;
	if (size > 0)
	{
		while (temp < size - 1 && src[temp] != '\0')
		{
			dest[temp] = src[temp];
			temp++;
		}
		dest[temp] = '\0';
	}
	while (src[temp] != '\0')
	{
		temp++;
	}
	return (temp);
}
