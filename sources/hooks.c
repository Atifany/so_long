/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:39:15 by atifany           #+#    #+#             */
/*   Updated: 2022/03/16 15:39:16 by atifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int keycode, t_game_data *g_d)
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

int	die_hook(void *g_d)
{
	error_die(EXIT_PRESSED, GRN, g_d);
	return (0);
}

int	loop_hook(t_game_data *g_d)
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
		draw_tile(g_d, (t_point){g_d->player_x, g_d->player_y});
	}
	return (0);
}
