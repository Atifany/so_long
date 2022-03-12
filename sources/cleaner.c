/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:13:32 by atifany           #+#    #+#             */
/*   Updated: 2022/03/12 14:13:34 by atifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	free_map(char ***map)
{
	int	i;

	i = 0;
	if (!*map)
		return ;
	while ((*map)[i])
		free((*map)[i++]);
	free(*map);
}

static void	free_sprites(s_game_data *g_d)
{
	if (g_d->images)
	{
		if (g_d->images->wall)
			mlx_destroy_image(g_d->mlx, g_d->images->wall);
		if (g_d->images->player)
			mlx_destroy_image(g_d->mlx, g_d->images->player);
		if (g_d->images->empty)
			mlx_destroy_image(g_d->mlx, g_d->images->empty);
		if (g_d->images->key)
			mlx_destroy_image(g_d->mlx, g_d->images->key);
		if (g_d->images->exit)
			mlx_destroy_image(g_d->mlx, g_d->images->exit);
	}
}

void	error_die(char *error_code, char *color, s_game_data *g_d)
{
	if (g_d)
	{
		free_map(&g_d->map);
		free_sprites(g_d);
		if (g_d->window)
			mlx_destroy_window(g_d->mlx, g_d->window);
	}
	ft_printf("%s%s%s", color, error_code, NC);
	exit(0);
}
