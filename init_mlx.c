/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:08:07 by raphox            #+#    #+#             */
/*   Updated: 2024/07/17 17:18:58 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"

void	init_mlx(t_struct *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_close_free(game);
	}
	game->win = mlx_new_window(game->mlx, game->x_axis * 64, game->y_axis * 64,
			"So_long");
	if (!game->win)
		ft_close_free(game);
	init_components_map(game);
	return ;
}

void	init_components_map(t_struct *game)
{
	game->wall = new_sprite(game, game->mlx, WALL_PATH);
	game->floor = new_sprite(game, game->mlx, FLOOR_PATH);
	game->collect = new_sprite(game, game->mlx, COLLECT_PATH);
	game->portal = new_sprite(game, game->mlx, PORTAL_PATH);
	game->player = new_sprite(game, game->mlx, PLAYER_PATH);
	return ;
}

t_img	new_sprite(t_struct *game, void *mlx, char *path)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	if (!img.ptr)
	{
		ft_close_free(game);
	}
	return (img);
}
