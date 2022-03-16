/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:35:45 by atifany           #+#    #+#             */
/*   Updated: 2022/03/11 18:35:46 by atifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_dubs_and_count_collect(t_game_data *g_d)
{
	char	alphabet[3];
	int		row;
	int		col;

	ft_bzero(alphabet, 3);
	row = 0;
	while (g_d->map[row])
	{
		col = 0;
		while (g_d->map[row][col])
		{
			if (g_d->map[row][col] == 'P')
				if (alphabet[0]++ != 0)
					error_die(INVALID_MAP_DUPLICATE, RED, g_d);
			if (g_d->map[row][col] == 'E')
				if (alphabet[1]++ != 0)
					error_die(INVALID_MAP_DUPLICATE, RED, g_d);
			if (g_d->map[row][col] == 'S')
				if (alphabet[2]++ != 0)
					error_die(INVALID_MAP_DUPLICATE, RED, g_d);
			if (g_d->map[row][col] == 'C')
				g_d->collectibles++;
			col++;
		}
		row++;
	}
}

static void	check_symbols_and_len(t_game_data *g_d)
{
	char	*alphabet;
	int		row;
	int		col;
	int		col_save;

	alphabet = "01PECS";
	row = 0;
	while (g_d->map[row])
	{
		col = 0;
		while (g_d->map[row][col])
		{
			if (!ft_strchr(alphabet, g_d->map[row][col]))
				error_die(INVALID_MAP_SYMBOLS, RED, g_d);
			col++;
		}
		if (row == 0)
			col_save = col;
		else
			if (col_save != col)
				error_die(INVALID_MAP_LINES, RED, g_d);
		row++;
	}
	g_d->rows = row;
	g_d->cols = col;
}

static void	check_if_closed_by_walls(t_game_data *g_d)
{
	int		row;
	int		col;

	row = 0;
	while (g_d->map[row])
	{
		col = 0;
		while (g_d->map[row][col])
		{
			if ((row == 0 || row == g_d->rows - 1
					|| col == 0 || col == g_d->cols - 1)
				&& g_d->map[row][col] != '1')
				error_die(INVALID_MAP_WALLS, RED, g_d);
			if (g_d->map[row][col] == 'P')
			{
				g_d->player_x = col;
				g_d->player_y = row;
			}
			if (g_d->map[row][col] == 'S')
			{
				g_d->enemy_x = col;
				g_d->enemy_y = row;
			}
			col++;
		}
		row++;
	}
}

void	validate_map(t_game_data *g_d)
{
	check_symbols_and_len(g_d);
	check_dubs_and_count_collect(g_d);
	check_if_closed_by_walls(g_d);
}
