/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:34:23 by agallet           #+#    #+#             */
/*   Updated: 2023/03/07 13:44:14 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	set_character(t_data_t *data, int *x, int *y)
{
	mlx_image_t	*temp;

	temp = data->map->floor;
	mlx_image_to_window(data->mlx, temp, *x, *y);
	temp = data->map->character.down;
	mlx_image_to_window(data->mlx, temp,
		*x + data->map->character.down->width / 2, *y + 10);
}

void	set_items(t_data_t *data, int *x, int *y)
{
	mlx_image_t	*temp;

	temp = data->map->floor;
	mlx_image_to_window(data->mlx, temp, *x, *y);
	temp = data->map->item;
	mlx_image_to_window(data->mlx, temp, *x, *y);
}

void	set_door(t_data_t *data, int *x, int *y)
{
	mlx_image_t	*temp;

	temp = data->map->door_close;
	mlx_image_to_window(data->mlx, temp, *x, *y);
	temp = data->map->door;
	mlx_image_to_window(data->mlx, temp, *x, *y);
}

/* Find texture */
mlx_image_t	*find_txt(char c, t_data_t *data, int *x, int *y)
{
	t_image_map_t	*txt;
	mlx_image_t		*temp;

	txt = data->map;
	temp = NULL;
	if (c == '0')
		temp = txt->floor;
	else if (c == '1')
		temp = txt->wall;
	else if (c == 'C')
		set_items(data, x, y);
	else if (c == 'E')
		set_door(data, x, y);
	else if (c == 'P')
		set_character(data, x, y);
	return (temp);
}
