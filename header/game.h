/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:30:29 by kadas             #+#    #+#             */
/*   Updated: 2026/04/19 18:31:34 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <unistd.h>
#include "../libft/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define NO 0
# define SO 1
# define WE 2
# define EA 3

typedef struct s_player
{
    double  x;
    double  y;
    double  dir_x;
    double  dir_y;
    double  vision_x;
    double  vision_y;
}   t_player;

typedef struct s_texture
{
    void    *img;
    int     *addr;
    int     width;
    int     height;
    int     bpp;
    int     line_len;
    int     endian;
}   t_texture;

typedef struct s_game
{
    char        **map;
    int         map_width;
    int         map_height;
    int         floor_color;
    int         ceiling_color;
    t_texture   textures[4];
    t_player    player;
    void        *mlx;
    void        *win;
    void        *img;
    int         *buf;
    int         bpp;
    int         line_len;
    int         endian;

} t_game;
char	*get_next_line(int fd);
char	*ft_strjoi(char *s1, char *s2);
char	**mapper(char *cub);
int	    isvalid(char **map);
void	free_all(char **words);
#endif
