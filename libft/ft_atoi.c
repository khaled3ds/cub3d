/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:46:15 by kadas             #+#    #+#             */
/*   Updated: 2025/08/11 14:42:12 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	*c;
	int		tmp;
	int		result;
	int		sign;

	sign = 1;
	c = (char *)nptr;
	tmp = 0;
	result = 0;
	while (nptr[tmp] == ' ' || (nptr[tmp] >= 9 && nptr[tmp] <= 13))
		tmp++;
	if (c[tmp] == '-' || c[tmp] == '+')
	{
		if (c[tmp] == '-')
			sign = -1;
		tmp++;
	}
	while (c[tmp] >= '0' && c[tmp] <= '9')
	{
		result = (c[tmp] - '0') + result * 10;
		tmp++;
	}
	return (result * sign);
}
