/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:45:10 by kadas             #+#    #+#             */
/*   Updated: 2026/05/13 01:56:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

static char	*map_reader(char *all, int fd)
{
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	if (!line)
	{
		free(all);
		return (NULL);
	}
	while (line)
	{
		tmp = all;
		all = ft_strjoi(tmp, line);
		free(line);
		if (!all)
			return (NULL);
		line = get_next_line(fd);
	}
	free(line);
	return (all);
}

char	**inputer(char *cub)
{
	int		fd;
	char	**map;
	char	*all;

	fd = open(cub, O_RDONLY);
	if (fd < 0)
		return (NULL);
	all = ft_strdup("");
	if (!all)
		return (NULL);
	all = map_reader(all, fd);
	close(fd);
	if (!all)
		return (NULL);
	map = ft_split(all, '\n');
	free(all);
	if (!map)
		return (NULL);
	return (map);
}
