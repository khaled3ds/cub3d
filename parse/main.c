/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:43:14 by kadas             #+#    #+#             */
/*   Updated: 2026/05/13 02:57:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

static void	right_input(int argc, char *argv)
{
	int	len;

	if (argc != 2)
	{
		write(2, "wrong number of argumnets", 26);
		exit(1);
	}
	len = ft_strlen(argv);
	if (len < 4 || ft_strncmp(&argv[len - 4], ".cub", 4))
	{
		write(2, "doesnt include .cub", 20);
		exit(1);
	}
}

int main(int argc,char **argv)
{
	char **file;
	t_game game;
	
    right_input(argc, argv[1]);
	file = inputer(argv[1]);
	if (!file)
		return (write(2, "Error\n", 6));
	parse_data(&game,file);
	if (!isvalid(game.map))
	{
		free_all(game.map);
		return (write(2, "Error\n", 6));
	}
}
