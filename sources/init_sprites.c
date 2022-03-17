/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:13:30 by atifany           #+#    #+#             */
/*   Updated: 2022/03/17 17:13:31 by atifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_sprites_3(t_game_data *g_d, t_sprites *images)
{
	images->enemy_1 = mlx_xpm_file_to_image(g_d->mlx,
			"assets/slime-1-right.xpm",
			&(g_d->img_width), &(g_d->img_height));
	if (!images->enemy_1)
		error_die(XPM_CONVERT_FAIL_ENEMY, RED, g_d);
	images->enemy_2 = mlx_xpm_file_to_image(g_d->mlx,
			"assets/slime-2-right.xpm",
			&(g_d->img_width), &(g_d->img_height));
	if (!images->enemy_2)
		error_die(XPM_CONVERT_FAIL_ENEMY, RED, g_d);
	images->enemy_1_left = mlx_xpm_file_to_image(g_d->mlx,
			"assets/slime-1-left.xpm",
			&(g_d->img_width), &(g_d->img_height));
	if (!images->enemy_1_left)
		error_die(XPM_CONVERT_FAIL_ENEMY, RED, g_d);
	images->enemy_2_left = mlx_xpm_file_to_image(g_d->mlx,
			"assets/slime-2-left.xpm",
			&(g_d->img_width), &(g_d->img_height));
	if (!images->enemy_2_left)
		error_die(XPM_CONVERT_FAIL_ENEMY, RED, g_d);
}

void	init_sprites_2(t_game_data *g_d, t_sprites *images)
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

void	init_sprites_1(t_game_data *g_d, t_sprites *images)
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
