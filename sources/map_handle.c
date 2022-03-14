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

static void	draw_map_helper(t_game_data *g_d, int i, int j)
{
	if (g_d->map[i][j] == '1')
		mlx_put_image_to_window(g_d->mlx, g_d->window,
			g_d->images->wall,
			j * g_d->img_width, i * g_d->img_height);
	else if (g_d->map[i][j] == '0')
		mlx_put_image_to_window(g_d->mlx, g_d->window,
			g_d->images->empty,
			j * g_d->img_width, i * g_d->img_height);
	else if (g_d->map[i][j] == 'E')
		mlx_put_image_to_window(g_d->mlx, g_d->window,
			g_d->images->exit,
			j * g_d->img_width, i * g_d->img_height);
	else if (g_d->map[i][j] == 'P')
	{
		g_d->player_x = j;
		g_d->player_y = i;
		mlx_put_image_to_window(g_d->mlx, g_d->window,
			g_d->images->empty,
			j * g_d->img_width, i * g_d->img_height);
		mlx_put_image_to_window(g_d->mlx, g_d->window,
			g_d->images->player_1,
			j * g_d->img_width, i * g_d->img_height);
	}
}

void	draw_map(t_game_data *g_d)
{
	int	i;
	int	j;

	i = 0;
	while (g_d->map[i])
	{
		j = 0;
		while (g_d->map[i][j])
		{
			draw_map_helper(g_d, i, j);
			if (g_d->map[i][j] == 'C')
			{
				mlx_put_image_to_window(g_d->mlx, g_d->window,
					g_d->images->empty,
					j * g_d->img_width, i * g_d->img_height);
				mlx_put_image_to_window(g_d->mlx, g_d->window,
					g_d->images->key,
					j * g_d->img_width, i * g_d->img_height);
			}
			j++;
		}
		i++;
	}
}
