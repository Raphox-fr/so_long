/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:18:39 by rafaria           #+#    #+#             */
/*   Updated: 2024/07/03 14:42:47 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(int argc, char **argv)
{
	t_struct	*game;

	game = malloc(sizeof(t_struct) * 1);
	if (game == NULL)
		return (0);
	parsing(argc, argv, game);
	game->string = read_map(argv[1], game);
	initialize_map(game, game->string);
	checks_maps(game, game->string, game->map);
	init_mlx(game);
	mlx_key_hook(game->win, key_hook, game);
	design_map(game);
	mlx_hook(game->win, 17, 0, &ft_close, game);
	mlx_loop(game->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	so_long(argc, argv);
	return (0);
}
