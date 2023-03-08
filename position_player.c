/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:38:37 by agallet           #+#    #+#             */
/*   Updated: 2023/03/07 13:44:15 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_right(mlx_instance_t wall, mlx_instance_t figure, t_data_t *data)
{
	int	width;
	int	height;

	width = data->map->character.down->width;
	height = 0;
	while (height < (int)data->map->character.down->height)
	{
		if (wall.x + 64 >= (figure.x + 5)
			&& wall.x <= (figure.x + 5 + width)
			&& (wall.y + 64 > figure.y + height && wall.y < figure.y + height))
			return (1);
		height++;
	}
	return (0);
}

int	wall_left(mlx_instance_t wall, mlx_instance_t figure, t_data_t *data)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	while (height < (int)data->map->character.down->height)
	{
		if (wall.x + 64 >= (figure.x - 5 + width)
			&& wall.x <= (figure.x - 5 + width)
			&& wall.y + 64 >= figure.y + height && wall.y <= figure.y + height)
			return (1);
		height++;
	}
	return (0);
}

int	wall_hight(mlx_instance_t wall, mlx_instance_t figure, t_data_t *data)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	while (width < (int)data->map->character.hight->width)
	{
		if (wall.y + 64 >= (figure.y - 5)
			&& wall.y <= (figure.y - 5)
			&& wall.x + 64 >= figure.x + width && wall.x <= figure.x + width)
			return (1);
		width++;
	}
	return (0);
}

int	wall_down(mlx_instance_t wall, mlx_instance_t figure, t_data_t *data)
{
	int	height;
	int	width;

	height = data->map->character.down->height;
	width = 0;
	while (width < (int)data->map->character.down->width)
	{
		if (wall.y + 64 >= (figure.y + 5 + height)
			&& wall.y <= (figure.y + 5 + height)
			&& wall.x + 64 >= figure.x + width && wall.x <= figure.x + width)
			return (1);
		width++;
	}
	return (0);
}
