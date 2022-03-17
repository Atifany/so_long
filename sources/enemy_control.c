/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:17:19 by atifany           #+#    #+#             */
/*   Updated: 2022/03/17 17:18:40 by atifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	find_dir(t_game_data *g_d, int *neighbours)
{
	int	i;
	int	min_path;
	int	dir;

	i = 0;
	dir = 0;
	min_path = g_d->rows + g_d->cols + 100;
	while (i < 4)
	{
		if (neighbours[i] < min_path)
		{
			min_path = neighbours[i];
			dir = i;
		}
		i++;
	}
	return (dir);
}

static t_point	choose_enemy_move(t_game_data *g_d)
{
	int	neighbours[4];
	int	i;
	int	dir;

	//do smth with this mess
	i = 0;
	while (i < 4)
		neighbours[i++] = g_d->rows + g_d->cols + 100;
	if (g_d->map[g_d->enemy_y - 1][g_d->enemy_x] != '1'
		&& g_d->map[g_d->enemy_y - 1][g_d->enemy_x] != 'C')
		neighbours[0] = (ft_abs(g_d->enemy_y - 1 - g_d->player_y)
				+ ft_abs(g_d->enemy_x - g_d->player_x));
	if (g_d->map[g_d->enemy_y][g_d->enemy_x + 1] != '1'
	&& g_d->map[g_d->enemy_y][g_d->enemy_x + 1] != 'C')
		neighbours[1] = (ft_abs(g_d->enemy_y - g_d->player_y)
				+ ft_abs(g_d->enemy_x + 1 - g_d->player_x));
	if (g_d->map[g_d->enemy_y + 1][g_d->enemy_x] != '1'
	&& g_d->map[g_d->enemy_y + 1][g_d->enemy_x] != 'C')
		neighbours[2] = (ft_abs(g_d->enemy_y + 1 - g_d->player_y)
				+ ft_abs(g_d->enemy_x - g_d->player_x));
	if (g_d->map[g_d->enemy_y][g_d->enemy_x - 1] != '1'
	&& g_d->map[g_d->enemy_y][g_d->enemy_x - 1] != 'C')
		neighbours[3] = (ft_abs(g_d->enemy_y - g_d->player_y)
				+ ft_abs(g_d->enemy_x - 1 - g_d->player_x));
	dir = find_dir(g_d, neighbours);
	if (dir == 0)
		return ((t_point){0, -1});
	else if (dir == 1)
		return ((t_point){1, 0});
	else if (dir == 2)
		return ((t_point){0, 1});
	else
		return ((t_point){-1, 0});
}

void	move_enemy(t_game_data *g_d)
{
	int		shift_x;
	int		shift_y;
	t_point	shift;

	shift = choose_enemy_move(g_d);
	shift_x = shift.x;
	shift_y = shift.y;
	if (shift_x < 0)
		g_d->enemy_is_facing_right = FALSE;
	else if (shift_x > 0)
		g_d->enemy_is_facing_right = TRUE;
	if (g_d->map[g_d->enemy_y + shift_y][g_d->enemy_x + shift_x] == '1'
		|| g_d->map[g_d->enemy_y + shift_y][g_d->enemy_x + shift_x] == 'E'
		|| g_d->map[g_d->enemy_y + shift_y][g_d->enemy_x + shift_x] == 'C')
		return ;
	if (g_d->map[g_d->enemy_y + shift_y][g_d->enemy_x + shift_x] == 'P')
		error_die(LOOSE_GAME, RED, g_d);
	g_d->map[g_d->enemy_y + shift_y][g_d->enemy_x + shift_x] = 'S';
	g_d->map[g_d->enemy_y][g_d->enemy_x] = '0';
	draw_tile(g_d,
		(t_point){g_d->enemy_x + shift_x, g_d->enemy_y + shift_y});
	draw_tile(g_d, (t_point){g_d->enemy_x, g_d->enemy_y});
	g_d->enemy_x = g_d->enemy_x + shift_x;
	g_d->enemy_y = g_d->enemy_y + shift_y;
}
