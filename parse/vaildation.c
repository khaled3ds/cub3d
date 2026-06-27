/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaildation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 18:16:12 by kadas             #+#    #+#             */
/*   Updated: 2026/05/13 21:14:14 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	in_bound(char **map, int i, int j)
{
	char	c;

	if (i < 0 || !map[i] || j < 0 || !map[i][j] || map[i][j] == ' ')
		return (0);
	c = map[i][j];
	if (c == '0')
		return (1);
	if (c == '1')
		return (1);
	if (c == 'W')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'N')
		return (1);
	if (c == 'S')
		return (1);
	return (0);
}

static int	walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1')
			{
				if (!in_bound(map, i, j + 1) || !in_bound(map, i, j - 1)
					|| !in_bound(map, i + 1, j) || !in_bound(map, i - 1, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N'
				&& map[i][j] != 'E' && map[i][j] != 'S' && map[i][j] != 'W'
				&& map[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	player(char **map)
{
	int	i;
	int	j;
	int	players;

	i = 0;
	players = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'E' || map[i][j] == 'W')
				players++;
			j++;
		}
		i++;
	}
	if (players == 1)
		return (1);
	return (0);
}

int	isvalid(char **map)
{
	if (!player(map) || !valid_char(map))
		return (0);
	if (!walls(map))
		return (0);
	return (1);
}
