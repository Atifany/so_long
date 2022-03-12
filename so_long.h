/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:36:12 by atifany           #+#    #+#             */
/*   Updated: 2022/03/11 18:36:07 by atifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "error_codes.h"
# include "get_next_line.h"
# include "colors.h"
# include "libs/mlx/mlx.h"
# include "libs/libft/libft.h"
# include "libs/ft_printf/ft_printf.h"
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define TRUE 1
# define FALSE 0
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct t_sprites
{
	void	*empty;
	void	*wall;
	void	*exit;
	void	*player;
	void	*key;
	//void	*wall_left;
	//void	*wall_right;
	//void	*wall_top;
	//void	*wall_botom;
} s_sprites;

typedef struct t_game_data
{
	void		*mlx;
	void		*window;
	char		**map;
	int			rows;
	int			cols;
	int			img_width;
	int			img_height;
	int			player_x;
	int			player_y;
	int			collectibles;
	s_sprites	*images;
} s_game_data;

// Utils
void	validate_map(s_game_data *g_d);
void	error_die(char *error_code, char *color, s_game_data *g_d);

// map_handle
char	**get_map(char *filename, s_game_data *g_d);
void	draw_map(s_game_data *g_d);
void	get_map_dims(s_game_data *g_d);

#endif
