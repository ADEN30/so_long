/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:38:37 by agallet           #+#    #+#             */
/*   Updated: 2023/03/07 13:44:14 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(t_data_t *data, int (*f)(mlx_instance_t, mlx_instance_t,
t_data_t *))
{
	int				i;
	mlx_instance_t	wall;
	mlx_instance_t	figure;

	i = 0;
	figure = *(enabled_instances(data));
	while (i < data->map->wall->count)
	{
		wall = data->map->wall->instances[i];
		if (f(wall, figure, data))
			return (0);
		i++;
	}
	return (1);
}

int	check_items(t_data_t *data, int (*f)(mlx_instance_t, mlx_instance_t,
t_data_t *))
{
	int				i;
	static int		count;
	mlx_instance_t	item;
	mlx_instance_t	figure;

	i = 0;
	figure = *(enabled_instances(data));
	while (i < data->map->item->count)
	{
		item = data->map->item->instances[i];
		if (f(item, figure, data))
		{
			data->map->item->instances[i].enabled = false;
			break ;
		}
		i++;
	}
	return (count);
}

int	check_door(t_data_t *data, int (*f)(mlx_instance_t, mlx_instance_t,
t_data_t *))
{
	int				i;
	static int		count;
	mlx_instance_t	item;
	mlx_instance_t	*figure;

	i = 0;
	figure = (enabled_instances(data));
	while (i < data->map->door->count)
	{
		item = data->map->door->instances[i];
		if (f(item, *figure, data))
		{
			mlx_close_window(data->mlx);
			break ;
		}
		i++;
	}
	return (count);
}

void	open_door(t_data_t *data)

{
	check_items(data, &wall_down);
	check_items(data, &wall_hight);
	check_items(data, &wall_left);
	check_items(data, &wall_right);
}

void	take_door(t_data_t *data)
{
	int				i;
	mlx_instance_t	*item;

	i = 0;
	while (i < data->map->item->count)
	{
		item = &data->map->item->instances[i];
		if (item->enabled)
			break ;
		else
		{
			check_door(data, &wall_down);
			check_door(data, &wall_hight);
			check_door(data, &wall_left);
			check_door(data, &wall_right);
		}
		i++;
	}
}
