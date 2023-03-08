/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:38:49 by agallet           #+#    #+#             */
/*   Updated: 2023/03/07 13:02:11 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_tabitem(int *tab, char c)
{
	if (c == 'C')
		tab[0] = tab[0] + 1;
	if (c == 'E')
		tab[2] = tab[2] + 1;
	if (c == 'P')
		tab[4] = tab[4] + 1;
}

int	*count_item(char **str)
{
	int	i;
	int	j;
	int	*nb;

	i = 0;
	j = 0;
	nb = malloc(sizeof(int) * (6));
	while (i < 6)
		nb[i++] = 0;
	i = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			set_tabitem(nb, str[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
	return (nb);
}

void	put_error(int *item)
{
	if (item[0] != item[1] && !item[2])
		write(1, "Error\nSomes items and the output aren't avaible\n", 49);
	else if (!item[0])
		write(1, "Error\nWe neeed one collectible\n", 33);
	else if (item[0] != item[1])
		write(1, "Error\nSomes items aren't avaible\n", 34);
	else if (item[2] != 1)
	{
		if (!item[2])
			write(1, "Error\nThe output is not avaible\n", 33);
		else
			write(1, "Error\nThere is more than one way out\n", 38);
	}
	else if (item[2] > 1)
		write(1, "Error\nThere is more than one start\n", 36);
}

int	floodfill(int x, int y, char **str, int *item)
{
	if (str[y][x] == 'C')
		item[1] += 1;
	if (str[y][x] == 'E')
		item[3] += 1;
	if (str[y][x] == 'P')
		item[5] += 1;
	if (str[y][x] != '0' && str[y][x] != 'P'
		&& str[y][x] != 'C' && str[y][x] != 'E')
		return (0);
	str[y][x] = '2';
	if (floodfill(x + 1, y, str, item))
		return (1);
	if (floodfill(x - 1, y, str, item))
		return (1);
	if (floodfill(x, y + 1, str, item))
		return (1);
	if (floodfill(x, y - 1, str, item))
		return (1);
	if (item[0] == item[1] && item[3] == 1 && item[5] == 1
		&& item[2] == item[3] && item[4] == item[5])
		return (1);
	return (0);
}
