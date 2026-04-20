/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:43:14 by kadas             #+#    #+#             */
/*   Updated: 2026/04/19 18:32:04 by kadas            ###   ########.fr       */
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
	char **map;
	
    right_input(argc, argv[1]);
	map = mapper(argv[1]);
	if (!map)
		return (write(2, "Error\n", 6));
	if (!isvalid(map))
	{
		free_all(map);
		return (write(2, "Error\n", 6));
	}
	
}