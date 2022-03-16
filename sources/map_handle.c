/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:01:08 by atifany           #+#    #+#             */
/*   Updated: 2022/03/12 15:01:09 by atifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**get_map(char *filename, t_game_data *g_d)
{
	int		fd;
	char	*line;
	char	*map;
	char	**ans;

	map = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_die(INVALID_TERM_CALL, RED, g_d);
	line = get_next_line(fd);
	while (line)
	{
		map = join(&map, line, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	ans = ft_split(map, '\n');
	free(map);
	return (ans);
}

void	draw_tile(t_game_data *g_d, t_point p)
{
	draw_map_helper_1(g_d, p.x, p.y);
	draw_map_helper_2(g_d, p.x, p.y);
}

void	draw_map(t_game_data *g_d)
{
	int			i;
	int			j;

	i = 0;
	while (g_d->map[i])
	{
		j = 0;
		while (g_d->map[i][j])
		{
			draw_tile(g_d, (t_point){j, i});
			j++;
		}
		i++;
	}
}
