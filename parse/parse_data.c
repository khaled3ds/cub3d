/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 01:47:52 by marvin            #+#    #+#             */
/*   Updated: 2026/06/05 10:32:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	not_map(char **file, int i)
{
	if (!file[i] || !file[i][0])
		return (0);
	if (file[i][0] == '0' || file[i][0] == '1' || file[i][0] == ' ')
		return (0);
	if (file[i][0] == 'E' && file[i][1] != 'A')
		return (0);
	if (file[i][0] == 'S' && file[i][1] != 'O')
		return (0);
	if (file[i][0] == 'N' && file[i][1] != 'O')
		return (0);
	if (file[i][0] == 'W' && file[i][1] != 'E')
		return (0);
	return (1);
}

static void	path_parser(char **file, int i, int j, t_game *game)
{
	j = 2;
	while (file[i][j] == ' ')
		j++;
	if (file[i][0] == 'N')
	{
		path_checker(game, NO);
		game->textures[NO].path = ft_substr(file[i], j, ft_strlen(file[i]) - j);
	}
	if (file[i][0] == 'S')
	{
		path_checker(game, SO);
		game->textures[SO].path = ft_substr(file[i], j, ft_strlen(file[i]) - j);
	}
	if (file[i][0] == 'E')
	{
		path_checker(game, EA);
		game->textures[EA].path = ft_substr(file[i], j, ft_strlen(file[i]) - j);
	}
	if (file[i][0] == 'W')
	{
		path_checker(game, WE);
		game->textures[WE].path = ft_substr(file[i], j, ft_strlen(file[i]) - j);
	}
}

static void	color_parser(char **file, int i, int j, t_game *game)
{
	int		arr[3];
	char	*substring;

	j = 1;
	while (file[i][j] == ' ')
		j++;
	substring = ft_substr(file[i], j, ft_strlen(file[i]) - j);
	if (!substring)
		exit(printf("malloc error"));
	color_parser_helper(arr, substring);
	j = (arr[0] << 16) | (arr[1] << 8) | arr[2];
	if (file[i][0] == 'C')
	{
		if (game->has_ceiling)
			exit(printf("duplicate ceiling color"));
		game->ceiling_color = j;
		game->has_ceiling = 1;
	}
	else
	{
		if (game->has_floor)
			exit(printf("duplicate floor color"));
		game->floor_color = j;
		game->has_floor = 1;
	}
}

static void	map_parser(char **file, int i, t_game *game)
{
	int		j;
	char	**map;
	int		i_copy;

	i_copy = i;
	j = 0;
	while (file[i_copy])
		i_copy++;
	map = malloc(sizeof(char *) * (i_copy - i + 1));
	if (!map)
		exit(printf("invalid malloc"));
	while (file[i])
	{
		map[j] = ft_strdup(file[i]);
		j++;
		i++;
	}
	map[j] = NULL;
	game->map = map;
}

void	parse_data(t_game *game, char **file)
{
	int	i;
	int	j;

	i = 0;
	while (file[i] && not_map(file, i))
	{
		j = 0;
		if (file[i][j] == 'N' || file[i][j] == 'S' || file[i][j] == 'E'
			|| file[i][j] == 'W')
			path_parser(file, i, j, game);
		else if (file[i][j] == 'C' || file[i][j] == 'F')
			color_parser(file, i, j, game);
		else
			exit(printf("invalid input"));
		i++;
	}
	if (!file[i])
		exit(printf("invalid input"));
	if (!game->textures[NO].path || !game->textures[SO].path
		|| !game->textures[WE].path || !game->textures[EA].path
		|| !game->has_floor || !game->has_ceiling)
		exit(printf("missing elements"));
	map_parser(file, i, game);
}
