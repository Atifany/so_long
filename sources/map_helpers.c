/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:39:47 by atifany           #+#    #+#             */
/*   Updated: 2022/03/16 15:41:59 by atifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	draw_map_helper_3(t_game_data *g_d, int x, int y)
{
	if (g_d->anim == TRUE)
	{
		if (g_d->is_facing_right == TRUE)
			mlx_put_image_to_window(g_d->mlx, g_d->window,
				g_d->images->player_1, x * g_d->img_width, y * g_d->img_height);
		else
			mlx_put_image_to_window(g_d->mlx, g_d->window,
				g_d->images->player_1_left, x * g_d->img_width,
				y * g_d->img_height);
	}
	else
	{
		if (g_d->is_facing_right == TRUE)
			mlx_put_image_to_window(g_d->mlx, g_d->window,
				g_d->images->player_2, x * g_d->img_width, y * g_d->img_height);
		else
			mlx_put_image_to_window(g_d->mlx, g_d->window,
				g_d->images->player_2_left, x * g_d->img_width,
				y * g_d->img_height);
	}
}

void	draw_map_helper_1(t_game_data *g_d, int x, int y)
{
	if (g_d->map[y][x] == '1')
		mlx_put_image_to_window(g_d->mlx, g_d->window,
			g_d->images->wall,
			x * g_d->img_width, y * g_d->img_height);
	else if (g_d->map[y][x] == '0')
		mlx_put_image_to_window(g_d->mlx, g_d->window,
			g_d->images->empty,
			x * g_d->img_width, y * g_d->img_height);
	else if (g_d->map[y][x] == 'E')
		mlx_put_image_to_window(g_d->mlx, g_d->window,
			g_d->images->exit,
			x * g_d->img_width, y * g_d->img_height);
	else if (g_d->map[y][x] == 'C')
	{
		mlx_put_image_to_window(g_d->mlx, g_d->window,
			g_d->images->empty,
			x * g_d->img_width, y * g_d->img_height);
		mlx_put_image_to_window(g_d->mlx, g_d->window,
			g_d->images->key,
			x * g_d->img_width, y * g_d->img_height);
	}
}

void	draw_map_helper_2(t_game_data *g_d, int x, int y)
{
	if (g_d->map[y][x] == 'P')
	{
		mlx_put_image_to_window(g_d->mlx, g_d->window,
			g_d->images->empty, x * g_d->img_width, y * g_d->img_height);
		draw_map_helper_3(g_d, x, y);
	}
}
