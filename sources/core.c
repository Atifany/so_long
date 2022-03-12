/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:36:19 by atifany           #+#    #+#             */
/*   Updated: 2022/03/09 17:36:20 by atifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	null_structs(s_game_data *g_d, s_sprites *images)
{
	images->wall = NULL;
	images->empty = NULL;
	images->player = NULL;
	images->key = NULL;
	images->exit = NULL;
	g_d->mlx = NULL;
	g_d->window = NULL;
	g_d->images = images;
	g_d->rows = 0;
	g_d->cols = 0;
	g_d->img_height = 0;
	g_d->img_width = 0;
	g_d->map = NULL;
}

static void	init_structs(char *map_name, s_game_data *g_d, s_sprites *images)
{
	char	*map;

	null_structs(g_d, images);
	map = ft_strjoin("maps/", map_name);
	g_d->map = get_map(map, g_d);
	free(map);
	validate_map(g_d);
	get_map_dims(g_d);
	g_d->mlx = mlx_init();
	g_d->window = mlx_new_window(g_d->mlx,
			g_d->cols * 64, g_d->rows * 64, "so_long");
	if (!(images->wall = mlx_xpm_file_to_image(g_d->mlx, "assets/wall.xpm",
											   &(g_d->img_width), &(g_d->img_height))))
		error_die(XPM_CONVERT_FAIL_WALL, g_d);
	if (!(images->empty = mlx_xpm_file_to_image(g_d->mlx, "assets/empty.xpm",
												&(g_d->img_width), &(g_d->img_height))))
		error_die(XPM_CONVERT_FAIL_EMPTY, g_d);
	if (!(images->player = mlx_xpm_file_to_image(g_d->mlx, "assets/player.xpm",
												&(g_d->img_width), &(g_d->img_height))))
		error_die(XPM_CONVERT_FAIL_PLAYER, g_d);
	if (!(images->exit = mlx_xpm_file_to_image(g_d->mlx, "assets/exit.xpm",
												&(g_d->img_width), &(g_d->img_height))))
		error_die(XPM_CONVERT_FAIL_EXIT, g_d);
	if (!(images->key = mlx_xpm_file_to_image(g_d->mlx, "assets/key.xpm",
												&(g_d->img_width), &(g_d->img_height))))
		error_die(XPM_CONVERT_FAIL_KEY, g_d);
	g_d->images = images;
}

static int	key_hook(int keycode, void *g_d)
{
	if (keycode == ESC)
		error_die(ESC_PRESSED, g_d);
	// add proper dying from pressing 'x' on a window
	return (0);
}

int	main(int argc, char **argv)
{
	s_game_data	g_d;
	s_sprites	images;

	if (argc != 2)
		error_die(INVALID_TERM_CALL, NULL);
	init_structs(argv[1], &g_d, &images);
	draw_map(&g_d);
	mlx_key_hook(g_d.window, key_hook, &g_d);
	mlx_loop(g_d.mlx);
	return (0);
}
