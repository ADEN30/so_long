/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:51:48 by agallet           #+#    #+#             */
/*   Updated: 2023/03/07 14:36:18 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*coordp(char **str)
{
	int	x;
	int	y;
	int	*coord;

	x = 0;
	y = 0;
	coord = malloc(sizeof(int) * (2));
	while (str[y])
	{
		while (str[y][x])
		{
			coord[1] = y;
			if (str[y][x] == 'P')
			{
				coord[0] = x;
				return (coord);
			}
			x++;
		}
		x = 0;
		y++;
	}
	free(coord);
	return (NULL);
}

int	condition_letters(char c)
{
	if (c != 'P' && c != 'E' && c != 'C' && c != '0' && c != '1' && c != '\n')
		return (0);
	else
		return (1);
}

int	around_map(char **str, int length)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] != '1')
			return (0);
		while (str[i][j])
		{
			if ((i == 0 || i == length - 1) && str[i][j] != '1'
				&& str[i][j] != '\n')
				return (0);
			if (str[i][j] == '\n')
				break ;
			j++;
		}
		if (str[i][j - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_line(char **str)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	length = ft_strlen(str[i]);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (condition_letters(str[i][j]))
				j++;
			else
				return (0);
		}
		if (length != ft_strlen(str[i]))
			return (0);
		i++;
	}
	if (i > length || !around_map(str, i))
		return (0);
	return (1);
}
