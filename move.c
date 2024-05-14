/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:13:03 by raphox            #+#    #+#             */
/*   Updated: 2024/05/09 18:34:01 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_struct *game)
{
	int	i;

	i = 0;
	if (game->map[game->y_player - 1][game->x_player] == '0'
		|| game->map[game->y_player - 1][game->x_player] == 'C'
		|| game->map[game->y_player - 1][game->x_player] == 'E')
	{
		if (find_player(game, 'C') == 1
			&& game->map[game->y_player - 1][game->x_player] == 'E')
			return (0);
		if (game->map[game->y_player - 1][game->x_player] == 'E')
			i = 1;
		game->map[game->y_player - 1][game->x_player] = PLAYER;
		game->map[game->y_player][game->x_player] = '0';
		game->moves = game->moves + 1;
		ft_itoa(game->moves);
		design_map(game);
		if (i == 1)
			ft_close(game);
	}
	return (0);
}

int	move_down(t_struct *game)
{
	int	i;

	i = 0;
	if (game->map[game->y_player + 1][game->x_player] == '0'
		|| game->map[game->y_player + 1][game->x_player] == 'C'
		|| game->map[game->y_player + 1][game->x_player] == 'E')
	{
		if (find_player(game, 'C') == 1
			&& game->map[game->y_player + 1][game->x_player] == 'E')
			return (0);
		if (game->map[game->y_player + 1][game->x_player] == 'E')
			i = 1;
		game->map[game->y_player + 1][game->x_player] = PLAYER;
		game->map[game->y_player][game->x_player] = '0';
		game->moves = game->moves + 1;
		ft_itoa(game->moves);
		design_map(game);
		if (i == 1)
			ft_close(game);
	}
	return (0);
}

int	move_left(t_struct *game)
{
	int	i;

	i = 0;
	if (game->map[game->y_player][game->x_player - 1] == '0'
		|| game->map[game->y_player][game->x_player - 1] == 'C'
		|| game->map[game->y_player][game->x_player - 1] == 'E')
	{
		if (find_player(game, 'C') == 1
			&& game->map[game->y_player][game->x_player - 1] == 'E')
			return (0);
		if (game->map[game->y_player][game->x_player - 1] == 'E')
			i = 1;
		game->map[game->y_player][game->x_player - 1] = PLAYER;
		game->map[game->y_player][game->x_player] = '0';
		game->moves = game->moves + 1;
		ft_itoa(game->moves);
		design_map(game);
		if (i == 1)
			ft_close(game);
	}
	return (0);
}

int	move_right(t_struct *game)
{
	int	i;

	i = 0;
	if (game->map[game->y_player][game->x_player + 1] == '0'
		|| game->map[game->y_player][game->x_player + 1] == 'C'
		|| game->map[game->y_player][game->x_player + 1] == 'E')
	{
		if (find_player(game, 'C') == 1
			&& game->map[game->y_player][game->x_player + 1] == 'E')
			return (0);
		if (game->map[game->y_player][game->x_player + 1] == 'E')
			i = 1;
		game->map[game->y_player][game->x_player + 1] = PLAYER;
		game->map[game->y_player][game->x_player] = '0';
		game->moves = game->moves + 1;
		ft_itoa(game->moves);
		design_map(game);
		if (i == 1)
			ft_close(game);
	}
	return (0);
}
