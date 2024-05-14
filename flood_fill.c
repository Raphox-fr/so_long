/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:24:59 by raphox            #+#    #+#             */
/*   Updated: 2024/05/12 20:20:22 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_struct *game, t_point size, t_point begin)
{
	fill(game, size, begin, game->map_to_fill[begin.y][begin.x]);
}

void	fill(t_struct *game, t_point size, t_point cur, char to_fill)
{
	if (game->map_to_fill[cur.y][cur.x] == 'C')
	{
		game->map_to_fill[cur.y][cur.x] = '0';
		game->collectibles_found++;
	}
	if (game->map_to_fill[cur.y][cur.x] == 'E')
	{
		game->map_to_fill[cur.y][cur.x] = '1';
		game->exit_found = 1;
	}
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| game->map_to_fill[cur.y][cur.x] != to_fill
		|| game->map_to_fill[cur.y][cur.x] != to_fill)
		return ;
	game->map_to_fill[cur.y][cur.x] = 'F';
	fill(game, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(game, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(game, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(game, size, (t_point){cur.x, cur.y + 1}, to_fill);
}
