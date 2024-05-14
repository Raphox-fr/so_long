/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaria <rafaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:19:54 by rafaria           #+#    #+#             */
/*   Updated: 2024/05/13 15:22:09 by rafaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsing(int argc, char **argv, t_struct *game)
{
	if (check_nb_of_args(argc) == -1 || check_name_map(argv[1]) == -1)
	{
		write(1, "Error\n", 6);
		free(game);
		exit(1);
	}
}

int	check_nb_of_args(int argc)
{
	if (argc == 1)
		return (-1);
	if (argc == 2)
		return (1);
	else
		return (-1);
	return (1);
}

int	check_name_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i >= 1 && str[i] == '.' && str[i + 1] == 'b' && str[i + 2] == 'e'
			&& str[i + 3] == 'r' && str[i + 4] == '\0')
			return (1);
		i++;
	}
	return (-1);
}

int	check_no_coquin(t_struct *game, char *str)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (str[x] != '\n')
		x++;
	x = x - 1;
	while (str[y] != '\0')
	{
		y++;
		if ((str[y] == '\n' || str[y] == '\0') && count != x)
			ft_light_close(game);
		else if ((str[y] == '\n' && count == x))
			count = -2;
		count++;
	}
	return (0);
}
