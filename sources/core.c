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

static void	put_str_on_window(t_game_data *g_d)
{
	static int	movements = 1;
	char		*str_1;
	char		*str_2;

	draw_tile(g_d, (t_point){0, 0});
	draw_tile(g_d, (t_point){1, 0});
	str_1 = "Movements: ";
	str_2 = ft_itoa(movements++);
	str_1 = ft_strjoin(str_1, str_2);
	mlx_string_put(g_d->mlx, g_d->window, 20, 20, 0xFFFFFFFF, str_1);
	free(str_1);
	free(str_2);
}

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

static void	decide_to_move_enemy(t_game_data *g_d)
{
	static char	is_enemy_moving = 0;

	if (is_enemy_moving++ == 0)
	{
		move_enemy(g_d);
		move_enemy(g_d);
	}
	if (is_enemy_moving == 4)
		is_enemy_moving = 0;
}

void	move(t_game_data *g_d, int shift_x, int shift_y)
{
	if (g_d->map[g_d->player_y + shift_y][g_d->player_x + shift_x] == 'S')
		error_die(LOOSE_GAME, RED, g_d);
	else if (g_d->map[g_d->player_y + shift_y][g_d->player_x + shift_x] == '1')
		return ;
	else if (g_d->map[g_d->player_y + shift_y][g_d->player_x + shift_x] == 'C')
		g_d->collectibles--;
	else if (g_d->map[g_d->player_y + shift_y][g_d->player_x + shift_x] == 'E')
	{
		if (g_d->collectibles != 0)
			return ;
		else
			error_die(WIN_GAME, GRN, g_d);
	}
	g_d->map[g_d->player_y + shift_y][g_d->player_x + shift_x] = 'P';
	g_d->map[g_d->player_y][g_d->player_x] = '0';
	draw_tile(g_d,
		(t_point){g_d->player_x + shift_x, g_d->player_y + shift_y});
	draw_tile(g_d, (t_point){g_d->player_x, g_d->player_y});
	g_d->player_x = g_d->player_x + shift_x;
	g_d->player_y = g_d->player_y + shift_y;
	put_str_on_window(g_d);
	if (g_d->enemy_x != 0)
		decide_to_move_enemy(g_d);
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
