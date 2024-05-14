/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Annexe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphox <raphox@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:20:32 by raphox            #+#    #+#             */
/*   Updated: 2024/05/09 18:59:34 by raphox           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	int_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_get_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

void	ft_fill_res(int size, int locate, int n, char *res)
{
	res[size] = '\0';
	while (size > locate)
	{
		res[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
	ft_putstr(res);
}

int	ft_itoa(int n)
{
	int		locate;
	int		size;
	char	*res;

	locate = 0;
	size = ft_get_size(n);
	res = malloc((sizeof(char) * size + 1));
	if (res == NULL)
		return (0);
	if (n == -2147483648)
	{
		res[0] = '-';
		res[1] = '2';
		n = 147483648;
		locate = 2;
	}
	if (n < 0)
	{
		res[0] = '-';
		locate = 1;
		n = -n;
	}
	ft_fill_res(size, locate, n, res);
	free(res);
	return (size);
}

int	ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (i);
}
