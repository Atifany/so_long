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
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define TRUE 1
# define FALSE 0

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
	s_sprites	*images;
} s_game_data;

// Utils
void	validate_map(s_game_data *g_d);
void	error_die(char *error_code, s_game_data *g_d);

#endif
