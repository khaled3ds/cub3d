/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 10:07:29 by kadas             #+#    #+#             */
/*   Updated: 2025/08/10 15:10:20 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	numlen(int n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		counter++;
	while (n)
	{
		counter++;
		n /= 10;
	}
	return (counter);
}

static char	*itoa_fill(char *c, long num, size_t i)
{
	c[i] = '\0';
	if (num > 0)
	{
		while (i > 0)
		{
			c[i - 1] = (num % 10) + '0';
			i--;
			num /= 10;
		}
	}
	else if (num < 0)
	{
		c[0] = '-';
		num = -num;
		while (i > 1)
		{
			c[i - 1] = (num % 10) + '0';
			i--;
			num /= 10;
		}
	}
	return (c);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*c;
	long	num;

	num = n;
	i = numlen(num);
	c = malloc(sizeof(char) * (i + 1));
	if (!c)
		return (NULL);
	if (num == 0)
	{
		c[1] = '\0';
		c[0] = '0';
		return (c);
	}
	else
		c = itoa_fill(c, num, i);
	return (c);
}
