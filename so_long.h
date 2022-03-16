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
	void	*player_1;
	void	*player_2;
	void	*player_1_left;
	void	*player_2_left;
	void	*enemy_1;
	void	*enemy_2;
	void	*enemy_1_left;
	void	*enemy_2_left;
	void	*key;
	//void	*wall_left;
	//void	*wall_right;
	//void	*wall_top;
	//void	*wall_botom;
}	t_sprites;

typedef struct s_game_data
{
	void		*mlx;
	void		*window;
	char		**map;
	int			rows;
	int			cols;
	int			img_width;
	int			img_height;
	int			collectibles;
	int			player_x;
	int			player_y;
	int			enemy_x;
	int			enemy_y;
	char		player_is_facing_right;
	char		enemy_is_facing_right;
	char		anim;
	t_sprites	*images;
}	t_game_data;

typedef struct s_point
{
	int	x;
	int	y;
} t_point;

// Utils
void	init_structs(char *map_name, t_game_data *g_d, t_sprites *images);
void	error_die(char *error_code, char *color, t_game_data *g_d);
void	validate_map(t_game_data *g_d);

// map_handle
char	**get_map(char *filename, t_game_data *g_d);
void	draw_tile(t_game_data *g_d, t_point p);
void	draw_map(t_game_data *g_d);

//map helpers
void	draw_map_helper_1(t_game_data *g_d, int x, int y);
void	draw_map_helper_2(t_game_data *g_d, int x, int y);

//hooks
void	move(t_game_data *g_d, int shift_x, int shift_y);
int		key_hook(int keycode, t_game_data *g_d);
int		loop_hook(t_game_data *g_d);
int		die_hook(void *g_d);

#endif
