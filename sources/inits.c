/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:12:24 by atifany           #+#    #+#             */
/*   Updated: 2022/03/14 17:13:30 by atifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	null_structs(t_game_data *g_d, t_sprites *images)
{
	images->wall = NULL;
	images->empty = NULL;
	images->player_1 = NULL;
	images->player_2 = NULL;
	images->key = NULL;
	images->exit = NULL;
	g_d->mlx = NULL;
	g_d->window = NULL;
	g_d->images = images;
	g_d->rows = 0;
	g_d->cols = 0;
	g_d->img_height = 0;
	g_d->img_width = 0;
	g_d->player_x = 0;
	g_d->player_y = 0;
	g_d->is_facing_right = TRUE;
	g_d->anim = TRUE;
	g_d->collectibles = 0;
	g_d->map = NULL;
}

static void	init_sprites_3(t_game_data *g_d, t_sprites *images)
{
	images->enemy_1 = mlx_xpm_file_to_image(g_d->mlx,
												  "assets/slime-1-right.xpm",
												  &(g_d->img_width), &(g_d->img_height));
	if (!images->enemy_1)
		error_die(XPM_CONVERT_FAIL_PLAYER, RED, g_d);
	images->enemy_2 = mlx_xpm_file_to_image(g_d->mlx,
												  "assets/slime-2-right.xpm",
												  &(g_d->img_width), &(g_d->img_height));
	if (!images->enemy_2)
		error_die(XPM_CONVERT_FAIL_PLAYER, RED, g_d);
	images->enemy_2_left = mlx_xpm_file_to_image(g_d->mlx,
												  "assets/slime-1-left.xpm",
												  &(g_d->img_width), &(g_d->img_height));
	if (!images->enemy_2_left)
		error_die(XPM_CONVERT_FAIL_PLAYER, RED, g_d);
	images->enemy_2_left = mlx_xpm_file_to_image(g_d->mlx,
												  "assets/slime-2-left.xpm",
												  &(g_d->img_width), &(g_d->img_height));
	if (!images->enemy_2_left)
		error_die(XPM_CONVERT_FAIL_PLAYER, RED, g_d);
}

static void	init_sprites_2(t_game_data *g_d, t_sprites *images)
{
	images->player_1_left = mlx_xpm_file_to_image(g_d->mlx,
			"assets/player-1-left.xpm",
			&(g_d->img_width), &(g_d->img_height));
	if (!images->player_1_left)
		error_die(XPM_CONVERT_FAIL_PLAYER, RED, g_d);
	images->player_2_left = mlx_xpm_file_to_image(g_d->mlx,
			"assets/player-2-left.xpm",
			&(g_d->img_width), &(g_d->img_height));
	if (!images->player_2_left)
		error_die(XPM_CONVERT_FAIL_PLAYER, RED, g_d);
	images->exit = mlx_xpm_file_to_image(g_d->mlx, "assets/door.xpm",
			&(g_d->img_width), &(g_d->img_height));
	if (!images->exit)
		error_die(XPM_CONVERT_FAIL_EXIT, RED, g_d);
	images->key = mlx_xpm_file_to_image(g_d->mlx, "assets/cake.xpm",
			&(g_d->img_width), &(g_d->img_height));
	if (!images->key)
		error_die(XPM_CONVERT_FAIL_KEY, RED, g_d);
	g_d->images = images;
}

static void	init_sprites_1(t_game_data *g_d, t_sprites *images)
{
	images->wall = mlx_xpm_file_to_image(g_d->mlx, "assets/wall.xpm",
			&(g_d->img_width), &(g_d->img_height));
	if (!images->wall)
		error_die(XPM_CONVERT_FAIL_WALL, RED, g_d);
	images->empty = mlx_xpm_file_to_image(g_d->mlx, "assets/floor.xpm",
			&(g_d->img_width), &(g_d->img_height));
	if (!images->empty)
		error_die(XPM_CONVERT_FAIL_PLAYER, RED, g_d);
	images->player_1 = mlx_xpm_file_to_image(g_d->mlx, "assets/player-1.xpm",
			&(g_d->img_width), &(g_d->img_height));
	if (!images->player_1)
		error_die(XPM_CONVERT_FAIL_PLAYER, RED, g_d);
	images->player_2 = mlx_xpm_file_to_image(g_d->mlx, "assets/player-2.xpm",
			&(g_d->img_width), &(g_d->img_height));
	if (!images->empty)
		error_die(XPM_CONVERT_FAIL_PLAYER, RED, g_d);
}

void	init_structs(char *map_name, t_game_data *g_d, t_sprites *images)
{
	char	*map;

	null_structs(g_d, images);
	map = ft_strjoin("maps/", map_name);
	g_d->map = get_map(map, g_d);
	free(map);
	validate_map(g_d);
	g_d->mlx = mlx_init();
	g_d->window = mlx_new_window(g_d->mlx,
			g_d->cols * 64, g_d->rows * 64, "so_long");
	init_sprites_1(g_d, images);
	init_sprites_2(g_d, images);
	init_sprites_3(g_d, images);
}
