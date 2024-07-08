/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:45:36 by rafaria           #+#    #+#             */
/*   Updated: 2024/07/08 17:02:18 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checks_maps(t_struct *game, char *str, char **map)
{
	check_map_valid(game, str);
	check_rectangular(game, str);
	check_wall_all_around(game, map);
	run_algo(game);
	check_no_coquin(game, game->string);
}

void	run_algo(t_struct *game)
{
	t_point	size;
	t_point	begin;

	find_player(game, 'P');
	size.x = game->x_axis - 1;
	size.y = game->y_axis - 1;
	begin.x = game->x_player;
	begin.y = game->y_player;
	game->collectibles_found = 0;
	game->exit_found = 0;
	game->map_to_fill[game->y_player][game->x_player] = '0';
	flood_fill(game, size, begin);
	if (game->collectibles_found != game->total_collectibles
		|| game->exit_found == 0)
		ft_light_close(game);
	return ;
}

void	check_map_valid(t_struct *game, char *str)
{
	int	i;
	int	c;
	int	ep;
	int	error;

	error = 0;
	c = 0;
	ep = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != 'C' && str[i] != 'E' && str[i] != 'P' && str[i] != '1'
			&& str[i] != '0' && str[i] != '\n' && str[i] != '\0')
			error++;
		if (str[i] == 'C')
			c++;
		if (str[i] == 'P' || str[i] == 'E')
			ep++;
		i++;
	}
	game->total_collectibles = c;
	if (ep == 2 && c >= 1 && error == 0)
		return ;
	ft_light_close(game);
}

void	check_rectangular(t_struct *game, char *str)
{
	int	etage;
	int	longueur;

	longueur = 0;
	etage = count_words(str, '\n');
	game->y_axis = etage;
	while (str[longueur] != '\n' && str[longueur] != '\0')
		longueur++;
	game->x_axis = longueur;
	if (game->x_axis > 30 || game->y_axis > 16)
		ft_light_close(game);
	if (longueur > etage)
		return ;
	ft_light_close(game);
}

void	check_wall_all_around(t_struct *game, char **map)
{
	int	i;
	int	valid;

	i = 0;
	valid = 0;
	while (map[0][i] == '1' && map[game->y_axis - 1][i] == '1'
		&& map[0][i] != '\0')
		i++;
	if (i == game->x_axis)
		valid++;
	i = 0;
	while (map[i][0] == '1' && map[i][game->x_axis - 1] == '1'
		&& i < game->y_axis - 1)
		i++;
	if (i == game->y_axis - 1)
		valid++;
	if (valid == 2)
		return ;
	ft_light_close(game);
}
