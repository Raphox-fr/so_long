/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:30:14 by raphox            #+#    #+#             */
/*   Updated: 2024/07/19 18:28:38 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**initialize_map(t_struct *game, char *str)
{
	char	**string;
	char	**string2;

	game->moves = 0;
	string = ft_split(str, '\n');
	string2 = ft_split(str, '\n');
	if ((string) == NULL || (string2 == NULL))
	{
		free(game);
		return (NULL);
	}
	game->map = string;
	game->map_to_fill = string2;
	return (string);
}

char	*read_map(char *file, t_struct *game)
{
	int		fd;
	char	*main_string;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		free(game);
		exit(1);
	}
	main_string = build_map(fd);
	if (main_string == NULL)
	{
		close(fd);
		free(main_string);
		free(game);
		write(1, "Error\n", 6);
		exit(1);
	}
	return (main_string);
}

void	design_map(t_struct *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	find_player(game, 'a');
	while (y < game->y_axis)
	{
		x = 0;
		while (x < game->x_axis)
		{
			build_images(game, x, y);
			x++;
		}
		y++;
	}
}

void	build_images(t_struct *game, int x, int y)
{
	if (game->map[y][x] == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->wall.ptr, x * 64, y
			* 64);
	if (game->map[y][x] == GROUND)
		mlx_put_image_to_window(game->mlx, game->win, game->floor.ptr, x * 64, y
			* 64);
	if (game->map[y][x] == COLLECTIBLES)
		mlx_put_image_to_window(game->mlx, game->win, game->collect.ptr, x * 64,
			y * 64);
	if (game->map[y][x] == PLAYER)
		mlx_put_image_to_window(game->mlx, game->win, game->player.ptr, x * 64,
			y * 64);
	if (game->map[y][x] == EXIT)
		mlx_put_image_to_window(game->mlx, game->win, game->portal.ptr, x * 64,
			y * 64);
}

int	find_player(t_struct *game, char str)
{
	int	y;
	int	x;
	int	found;

	y = 0;
	found = 0;
	while (y < game->y_axis)
	{
		x = 0;
		while (x < game->x_axis)
		{
			if (game->map[y][x] == PLAYER)
			{
				game->x_player = x;
				game->y_player = y;
			}
			if (game->map[y][x] == str)
				found++;
			x++;
		}
		y++;
	}
	if (found >= 1)
		return (1);
	return (-1);
}
