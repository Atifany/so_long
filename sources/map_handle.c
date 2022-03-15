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

static void	map_to_term(t_game_data *g_d)
{
	int i;

	i = 0;
	while (g_d->map[i])
	{
		ft_printf("%s|%s|%s\n", CYN, g_d->map[i], NC);
		i++;
	}
	ft_printf("\n");
}

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

static void	draw_map_helper_1(t_game_data *g_d, int x, int y)
{
	if (g_d->map[y][x] == '1')
		mlx_put_image_to_window(g_d->mlx, g_d->window,
			g_d->images->wall,
			x * g_d->img_width, y * g_d->img_height);
	else if (g_d->map[y][x] == '0')
		mlx_put_image_to_window(g_d->mlx, g_d->window,
			g_d->images->empty,
			x * g_d->img_width, y * g_d->img_height);
	else if (g_d->map[y][x] == 'E')
		mlx_put_image_to_window(g_d->mlx, g_d->window,
			g_d->images->exit,
			x * g_d->img_width, y * g_d->img_height);
	else if (g_d->map[y][x] == 'C')
	{
		mlx_put_image_to_window(g_d->mlx, g_d->window,
			g_d->images->empty,
			x * g_d->img_width, y * g_d->img_height);
		mlx_put_image_to_window(g_d->mlx, g_d->window,
			g_d->images->key,
			x * g_d->img_width, y * g_d->img_height);
	}
}

static void	draw_map_helper_3(t_game_data *g_d, int x, int y)
{
	if (g_d->anim == TRUE)
	{
		if (g_d->is_facing_right == TRUE)
			mlx_put_image_to_window(g_d->mlx, g_d->window,
				g_d->images->player_1, x * g_d->img_width, y * g_d->img_height);
		else
			mlx_put_image_to_window(g_d->mlx, g_d->window,
				g_d->images->player_1_left, x * g_d->img_width,
				y * g_d->img_height);
	}
	else
	{
		if (g_d->is_facing_right == TRUE)
			mlx_put_image_to_window(g_d->mlx, g_d->window,
				g_d->images->player_2, x * g_d->img_width, y * g_d->img_height);
		else
			mlx_put_image_to_window(g_d->mlx, g_d->window,
				g_d->images->player_2_left, x * g_d->img_width,
				y * g_d->img_height);
	}
}

static void	draw_map_helper_2(t_game_data *g_d, int x, int y)
{
	if (g_d->map[y][x] == 'P')
	{
		g_d->player_x = x;
		g_d->player_y = y;
		mlx_put_image_to_window(g_d->mlx, g_d->window,
			g_d->images->empty, x * g_d->img_width, y * g_d->img_height);
		draw_map_helper_3(g_d, x, y);
	}
}

void	draw_map(t_game_data *g_d, void *p_from, void *p_to)
{
	int			i;
	int			j;

	map_to_term(g_d);
	if (((t_point *)p_from) && ((t_point *)p_to))
	{
		ft_printf("%sfrom: |%d|%d|\n to: |%d|%d|\n%s", RED, ((t_point *)p_from)->x, ((t_point *)p_from)->y,
			((t_point *)p_to)->x, ((t_point *)p_to)->y,NC);
		draw_map_helper_1(g_d, ((t_point *)p_from)->x, ((t_point *)p_from)->y);
		draw_map_helper_2(g_d, ((t_point *)p_from)->x, ((t_point *)p_from)->y);
		draw_map_helper_1(g_d, ((t_point *)p_to)->x, ((t_point *)p_to)->y);
		draw_map_helper_2(g_d, ((t_point *)p_to)->x, ((t_point *)p_to)->y);
		return ;
	}
	i = 0;
	while (g_d->map[i])
	{
		j = 0;
		while (g_d->map[i][j])
		{
			draw_map_helper_1(g_d, j, i);
			draw_map_helper_2(g_d, j, i);
			j++;
		}
		i++;
	}
}
