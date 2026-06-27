/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 19:46:40 by kadas             #+#    #+#             */
/*   Updated: 2026/06/05 10:37:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	free_all(char **words)
{
	int	i;

	i = 0;
	if (!words)
		return ;
	while (words[i])
		free(words[i++]);
	free(words);
}

void	path_checker(t_game *game, int i)
{
	if (game->textures[i].path)
		exit(printf("duplicate texture"));
}

void	color_parser_helper(int arr[], char *substring)
{
	char	**strings;
	int		k;

	k = -1;
	strings = ft_split(substring, ',');
	if (!strings)
		exit(printf("malloc error"));
	if (!strings[0] || !strings[1] || !strings[2])
		exit(printf("invalid color format"));
	while (++k < 3)
		arr[k] = ft_atoi(strings[k]);
	if (arr[0] < 0 || arr[0] > 255 || arr[1] < 0 || arr[1] > 255 || arr[2] < 0
		|| arr[2] > 255)
		exit(printf("invlaid numbers"));
	free_all(strings);
	free(substring);
}

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->textures[i].path)
			free(game->textures[i].path);
		i++;
	}
	free_all(game->map);
}
