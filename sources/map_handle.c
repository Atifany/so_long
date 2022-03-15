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

static void	draw_map_helper_1(t_game_data *g_d, int i, int j)
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
	else if (g_d->map[i][j] == 'C')
	{
		mlx_put_image_to_window(g_d->mlx, g_d->window,
			g_d->images->empty,
			j * g_d->img_width, i * g_d->img_height);
		mlx_put_image_to_window(g_d->mlx, g_d->window,
			g_d->images->key,
			j * g_d->img_width, i * g_d->img_height);
	}
}

static void	draw_map_helper_3(t_game_data *g_d, int i, int j)
{
	if (g_d->anim == TRUE)
	{
		if (g_d->is_facing_right == TRUE)
			mlx_put_image_to_window(g_d->mlx, g_d->window,
				g_d->images->player_1, j * g_d->img_width, i * g_d->img_height);
		else
			mlx_put_image_to_window(g_d->mlx, g_d->window,
				g_d->images->player_1_left, j * g_d->img_width,
				i * g_d->img_height);
	}
	else
	{
		if (g_d->is_facing_right == TRUE)
			mlx_put_image_to_window(g_d->mlx, g_d->window,
				g_d->images->player_2, j * g_d->img_width, i * g_d->img_height);
		else
			mlx_put_image_to_window(g_d->mlx, g_d->window,
				g_d->images->player_2_left, j * g_d->img_width,
				i * g_d->img_height);
	}
}

static void	draw_map_helper_2(t_game_data *g_d, int i, int j)
{
	if (g_d->map[i][j] == 'P')
	{
		g_d->player_x = j;
		g_d->player_y = i;
		mlx_put_image_to_window(g_d->mlx, g_d->window,
			g_d->images->empty, j * g_d->img_width, i * g_d->img_height);
		draw_map_helper_3(g_d, i, j);
	}
}

void	draw_map(t_game_data *g_d)
{
	static char	**map_s;
	char		flag;
	int			i;
	int			j;

	flag = FALSE;
	if (!map_s)
	{
		map_s = g_d->map;
		flag = TRUE;
	}
	i = 0;
	while (g_d->map[i])
	{
		j = 0;
		while (g_d->map[i][j])
		{
			if (g_d->map[i][j] != map_s[i][j] || flag == TRUE)
			{
				ft_printf("%sFLAG: |%d|%s\n", CYN, flag, NC);
				ft_printf("%s|%s|\n|%s|\n|%s|\n|%s|\n|%s|\n%s", YEL, map_s[0], map_s[1], map_s[2], map_s[3], map_s[4], NC);
				ft_printf("%s|%s|\n|%s|\n|%s|\n|%s|\n|%s|\n%s", RED, g_d->map[0], g_d->map[1], g_d->map[2], g_d->map[3], g_d->map[4], NC);
				draw_map_helper_1(g_d, i, j);
				draw_map_helper_2(g_d, i, j);
			}
			j++;
		}
		i++;
	}
	map_s = g_d->map;
}
