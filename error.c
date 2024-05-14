/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:16:18 by raphox            #+#    #+#             */
/*   Updated: 2024/05/09 19:39:09 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_struct *game)
{
	mlx_destroy_image(game->mlx, game->floor.ptr);
	mlx_destroy_image(game->mlx, game->wall.ptr);
	mlx_destroy_image(game->mlx, game->collect.ptr);
	mlx_destroy_image(game->mlx, game->portal.ptr);
	mlx_destroy_image(game->mlx, game->player.ptr);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
	free(game->string);
	free_map(game->map);
	free_map(game->map_to_fill);
	free(game->mlx);
	free(game);
	exit(1);
}

int	ft_light_close(t_struct *game)
{
	write(1, "Error\n", 6);
	free(game->string);
	free_map(game->map);
	free_map(game->map_to_fill);
	free(game);
	exit(1);
}

char	**free_map(char **tab)
{
	int	j;

	j = 0;
	while (tab[j])
	{
		free(tab[j]);
		j++;
	}
	free(tab);
	return (NULL);
}
