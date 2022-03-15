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
	char		window_string[21];
	char		*movements_str;

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
	draw_map(g_d, &(t_point){g_d->player_y, g_d->player_x}, &(t_point){g_d->player_y + shift_x, g_d->player_x + shift_y});
	ft_strlcpy(window_string, "Movements: ", 11);
	movements_str = ft_itoa(movements++);
	ft_strlcat(window_string, movements_str, 21);
	mlx_string_put(g_d->mlx, g_d->window, 20, 20, 0xFFFFFFFF, window_string);
}

static int	key_hook(int keycode, t_game_data *g_d)
{
	if (keycode == ESC)
		error_die(ESC_PRESSED, GRN, g_d);
	if (keycode == W)
		move(g_d, 0, -1);
	if (keycode == A)
	{
		g_d->is_facing_right = FALSE;
		move(g_d, -1, 0);
	}
	if (keycode == S)
		move(g_d, 0, 1);
	if (keycode == D)
	{
		g_d->is_facing_right = TRUE;
		move(g_d, 1, 0);
	}
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

	if (clock++ < 2000)
		return (0);
	else
	{
		clock = 0;
		if (g_d->anim == FALSE)
			g_d->anim = TRUE;
		else
			g_d->anim = FALSE;
		draw_map(g_d, &(t_point){g_d->player_y, g_d->player_x}, &(t_point){g_d->player_y, g_d->player_x});
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
	draw_map(&g_d, NULL, NULL);
	mlx_key_hook(g_d.window, key_hook, &g_d);
	mlx_hook(g_d.window, 17, 0L, die_hook, &g_d);
	mlx_loop_hook(g_d.mlx, loop_hook, &g_d);
	mlx_loop(g_d.mlx);
	return (0);
}
