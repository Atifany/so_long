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

static void	free_map(char ***map)
{
	int	i;

	i = 0;
	while ((*map)[i])
		free((*map)[i++]);
	free(*map);
}
/*
static void	free_sprites(s_game_data *g_d)
{

}
*/
void error_die(char *error_code, s_game_data *g_d)
{
	ft_printf("%s%s%s", RED, error_code, NC);
	if (g_d)
	{
		free_map(&g_d->map);
		mlx_destroy_window(g_d->mlx, g_d->window);
	}
	exit(0);
}

static char	**get_map(char *filename, s_game_data *g_d)
{
	int		fd;
	char	*line;
	char	*map;
	char	**ans;

	map = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_die(INVALID_TERM_CALL, g_d);
	line = get_next_line(fd);
	while (line)
	{
		map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	ans = ft_split(map, '\n');
	free(map);
	return (ans);
}

static void	draw_map(s_game_data *g_d)
{
	int	i;
	int	j;

	i = 0;
	while (g_d->map[i])
	{
		j = 0;
		while (g_d->map[i][j])
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
				mlx_put_image_to_window(g_d->mlx, g_d->window,
										g_d->images->empty,
										j * g_d->img_width, i * g_d->img_height);
				mlx_put_image_to_window(g_d->mlx, g_d->window,
										g_d->images->player,
										j * g_d->img_width, i * g_d->img_height);
			}
			else if (g_d->map[i][j] == 'C')
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

static void	get_map_dims(s_game_data *g_d)
{
	char	**map;
	int		rows;
	int		cols;

	map = g_d->map;
	rows = 0;
	while (map[rows])
	{
		cols = 0;
		while (map[rows][cols])
			cols++;
		rows++;
	}
	g_d->rows = rows;
	g_d->cols = cols;
}

static void	init_structs(char *map_filename, s_game_data *g_d, s_sprites *images)
{
	char	*map_name;

	g_d->map = NULL;
	map_name = ft_strjoin("maps/", map_filename);
	g_d->mlx = mlx_init();
	g_d->map = get_map(map_name, g_d);
	free(map_name);
	validate_map(g_d);
	get_map_dims(g_d);
	g_d->window = mlx_new_window(g_d->mlx, g_d->cols * 64, g_d->rows * 64, "so_long");
	if (!(images->wall = mlx_xpm_file_to_image(g_d->mlx, "assets/wall.xpm",
											   &(g_d->img_width), &(g_d->img_height))))
		error_die(XPM_CONVERT_FAIL_WALL, g_d);
	if (!(images->empty = mlx_xpm_file_to_image(g_d->mlx, "assets/empty.xpm",
												&(g_d->img_width), &(g_d->img_height))))
		error_die(XPM_CONVERT_FAIL_EMPTY, g_d);
	if (!(images->player = mlx_xpm_file_to_image(g_d->mlx, "assets/player.xpm",
												&(g_d->img_width), &(g_d->img_height))))
		error_die(XPM_CONVERT_FAIL_PLAYER, g_d);
	if (!(images->exit = mlx_xpm_file_to_image(g_d->mlx, "assets/exit.xpm",
												&(g_d->img_width), &(g_d->img_height))))
		error_die(XPM_CONVERT_FAIL_EXIT, g_d);
	if (!(images->key = mlx_xpm_file_to_image(g_d->mlx, "assets/key.xpm",
												&(g_d->img_width), &(g_d->img_height))))
		error_die(XPM_CONVERT_FAIL_KEY, g_d);
	g_d->images = images;
}

int main(int argc, char **argv)
{
	s_game_data	g_d;
	s_sprites	images;

	if (argc != 2)
		error_die(INVALID_TERM_CALL, NULL);
	init_structs(argv[1], &g_d, &images);
	draw_map(&g_d);
	mlx_loop(g_d.mlx);
	return (0);
}
