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

static void	check_dubs_and_count_collect(s_game_data *g_d)
{
	char	alphabet[2];
	int		row;
	int		col;
	ft_bzero(alphabet, 2);
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
			if (g_d->map[row][col] == 'C')
				g_d->collectibles++;
			col++;
		}
		row++;
	}
}

static void	check_symbols_and_len(s_game_data *g_d)
{
	char	*alphabet;
	int		row;
	int		col;
	int		col_save;

	alphabet = "01PEC";
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
}

void	validate_map(s_game_data *g_d)
{
	check_symbols_and_len(g_d);
	check_dubs_and_count_collect(g_d);
	// add validation for walls. I mean check if all the borders of the map are actually walls!
}
