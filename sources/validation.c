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
				error_die(INVALID_MAP_SYMBOLS, g_d);
			col++;
		}
		if (row == 0)
			col_save = col;
		else
			if (col_save != col)
				error_die(INVALID_MAP_LINES, g_d);
		row++;
	}
}

void	validate_map(s_game_data *g_d)
{
	check_symbols_and_len(g_d);
	//add check if there are more than one players and/or exit on a map!
}
