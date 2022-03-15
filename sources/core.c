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

static void	move(t_game_data *g_d, int shift_x, int shift_y)
{
	static int	movements = 0;

	if (g_d->map[g_d->player_y + shift_y][g_d->player_x + shift_x] == '1')
		return ;
	else
	{
		if (g_d->map[g_d->player_y + shift_y][g_d->player_x + shift_x] == 'C')
			g_d->collectibles--;
		if (g_d->map[g_d->player_y + shift_y][g_d->player_x + shift_x] == 'E')
		{
			if (g_d->collectibles != 0)
				return ;
			else
				error_die(WIN_GAME, GRN, g_d);
		}
		g_d->map[g_d->player_y + shift_y][g_d->player_x + shift_x] = 'P';
		g_d->map[g_d->player_y][g_d->player_x] = '0';
	}
	draw_map(g_d);
	ft_printf("%sMovements: %d%s\n", YEL, movements++, NC);
}

static int	key_hook(int keycode, t_game_data *g_d)
{
	if (keycode == ESC)
		error_die(ESC_PRESSED, GRN, g_d);
	if (keycode == W)
		move(g_d, 0, -1);
	if (keycode == A)
		move(g_d, -1, 0);
	if (keycode == S)
		move(g_d, 0, 1);
	if (keycode == D)
		move(g_d, 1, 0);
	return (0);
}

static int	die_hook(void *g_d)
{
	error_die(EXIT_PRESSED, GRN, g_d);
	return (0);
}

static int	loop_hook(t_game_data *g_d)
{
	static int	clock = 0;
	if (clock < 100)
	{
		clock++;
		return (0);
	}
	else
	{
		clock = 0;
		g_d->map[g_d->player_y][g_d->player_x] = 'p';
		draw_map(g_d);
		g_d->map[g_d->player_y][g_d->player_x] = 'P';
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game_data	g_d;
	t_sprites	images;

	if (argc != 2)
		error_die(INVALID_TERM_CALL, RED, NULL);
	init_structs(argv[1], &g_d, &images);
	draw_map(&g_d);
	mlx_key_hook(g_d.window, key_hook, &g_d);
	mlx_hook(g_d.window, 17, 0L, die_hook, &g_d);
	mlx_loop_hook(g_d.mlx, loop_hook, &g_d);
	mlx_loop(g_d.mlx);
	return (0);
}
