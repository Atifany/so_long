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

static void error_die(char *error_code)
{
	if (!ft_strncmp(error_code, ".xpm->image", 1024))
	{
		ft_printf("%sError.\nFailed to convert .xpm file to an image.\n%s", RED, NC);
		exit(0);
	}
}

static char	**get_map(char *filename)
{
	int		fd;
	char	*line;
	char	*map;

	map = NULL;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (ft_split(map, '\n'));
}

static void	draw_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')

			j++;
		}
		i++;
	}
}

int main()
{
	void	*mlx;
	void	*window;
	void	*img;
	int		img_width;
	int 	img_heigth;
	char	**map;

	map = get_map("maps/little_map.ber");
	draw_map(map);
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1920, 1024, "so_long");
	if (!(img = mlx_xpm_file_to_image(mlx, "assets/Bacon_64.xpm", &img_width, &img_heigth)))
		error_die(".xpm->image");
	mlx_put_image_to_window(mlx, window, img, 500, 500);
	mlx_string_put(mlx, window, 30, 30, 0xFF00FFFF, "KEKS?");
	mlx_loop(mlx);
	return (0);
}
