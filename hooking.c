/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:49:28 by raphox            #+#    #+#             */
/*   Updated: 2024/05/09 19:01:36 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_struct *game)
{
	if (keycode == UP || keycode == REALUP)
		move_up(game);
	if (keycode == DOWN || keycode == REALDOWN)
		move_down(game);
	if (keycode == RIGHT || keycode == REALRIGHT)
		move_right(game);
	if (keycode == LEFT || keycode == REALLEFT)
		move_left(game);
	if (keycode == ESC)
		ft_close(game);
	return (0);
}
