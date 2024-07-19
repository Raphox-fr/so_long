/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:16:18 by raphox            #+#    #+#             */
/*   Updated: 2024/07/19 15:29:34 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_struct *game)
{
	if (game->portal.ptr)
		mlx_destroy_image(game->mlx, game->portal.ptr);
	if (game->player.ptr)
		mlx_destroy_image(game->mlx, game->player.ptr);
	if (game->floor.ptr)
		mlx_destroy_image(game->mlx, game->floor.ptr);
	if (game->wall.ptr)
		mlx_destroy_image(game->mlx, game->wall.ptr);
	if (game->collect.ptr)
		mlx_destroy_image(game->mlx, game->collect.ptr);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
	free(game->string);
	free_map(game->map);
	free_map(game->map_to_fill);
	free(game->mlx);
	free(game);
	exit(0);
}

int	ft_close_free(t_struct *game)
{
	if (game->portal.ptr)
		mlx_destroy_image(game->mlx, game->portal.ptr);
	if (game->player.ptr)
		mlx_destroy_image(game->mlx, game->player.ptr);
	if (game->floor.ptr)
		mlx_destroy_image(game->mlx, game->floor.ptr);
	if (game->wall.ptr)
		mlx_destroy_image(game->mlx, game->wall.ptr);
	if (game->collect.ptr)
		mlx_destroy_image(game->mlx, game->collect.ptr);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
	free(game->string);
	free_map(game->map);
	free_map(game->map_to_fill);
	free(game->mlx);
	free(game);
	exit(0);
}

int	init_all(t_struct *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->string = NULL;
	game->map = NULL;
	game->map_to_fill = NULL;
	game->floor.ptr = NULL;
	game->wall.ptr = NULL;
	game->collect.ptr = NULL;
	game->portal.ptr = NULL;
	game->player.ptr = NULL;
	return (0);
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
	if (!tab)
		return (NULL);
	while (tab[j])
	{
		free(tab[j]);
		j++;
	}
	free(tab);
	return (NULL);
}
