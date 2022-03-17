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

static void	null_sprites(t_sprites *images)
{
	images->wall = NULL;
	images->empty = NULL;
	images->player_1 = NULL;
	images->player_2 = NULL;
	images->enemy_1 = NULL;
	images->enemy_2 = NULL;
	images->player_1_left = NULL;
	images->player_2_left = NULL;
	images->enemy_1_left = NULL;
	images->enemy_2_left = NULL;
	images->key = NULL;
	images->exit = NULL;
}

static void	null_game_data(t_game_data *g_d, t_sprites *images)
{
	null_sprites(images);
	g_d->images = images;
	g_d->mlx = NULL;
	g_d->window = NULL;
	g_d->rows = 0;
	g_d->cols = 0;
	g_d->img_height = 0;
	g_d->img_width = 0;
	g_d->player_x = 0;
	g_d->player_y = 0;
	g_d->enemy_x = 0;
	g_d->enemy_y = 0;
	g_d->player_is_facing_right = TRUE;
	g_d->enemy_is_facing_right = TRUE;
	g_d->anim = TRUE;
	g_d->collectibles = 0;
	g_d->map = NULL;
}

void	init_structs(char *map_name, t_game_data *g_d, t_sprites *images)
{
	char	*map;

	null_game_data(g_d, images);
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
