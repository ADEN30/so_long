/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:54:25 by agallet           #+#    #+#             */
/*   Updated: 2023/03/07 13:46:19 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	key_press_up(t_data_t *data)
{
	t_image_character_t		*figure;
	mlx_instance_t			*inst;

	figure = &data->map->character;
	inst = enabled_instances(data);
	if (inst->y)
		inst->enabled = false;
	if (figure->hight->instances)
	{
		if (figure->hight->instances[0].enabled == false)
			figure->hight->instances[0].enabled = true;
		figure->hight->instances[0].y = inst->y - 5;
		figure->hight->instances[0].x = inst->x;
		data->after = data->after + 5;
	}
	else
		mlx_image_to_window(data->mlx, figure->hight, inst->x, inst->y - 5);
}

void	key_press_down(t_data_t *data)
{
	t_image_character_t		*figure;
	mlx_instance_t			*inst;

	figure = &data->map->character;
	inst = enabled_instances(data);
	if (inst->y)
		inst->enabled = false;
	if (figure->down->instances)
	{
		if (figure->down->instances[0].enabled == false)
			figure->down->instances[0].enabled = true;
		figure->down->instances[0].y = inst->y + 5;
		figure->down->instances[0].x = inst->x;
		data->after = data->after + 5;
	}
	else
		mlx_image_to_window(data->mlx, figure->down, inst->x, inst->y - 5);
}

void	key_press_left(t_data_t *data)
{
	t_image_character_t		*figure;
	mlx_instance_t			*inst;

	figure = &data->map->character;
	inst = enabled_instances(data);
	if (inst->y)
		inst->enabled = false;
	if (figure->left->instances)
	{
		if (figure->left->instances[0].enabled == false)
			figure->left->instances[0].enabled = true;
		figure->left->instances[0].y = inst->y;
		figure->left->instances[0].x = inst->x - 5;
		data->after = data->after + 5;
	}
	else
		mlx_image_to_window(data->mlx, figure->left, inst->x - 5, inst->y);
}

void	key_press_right(t_data_t *data)
{
	t_image_character_t		*figure;
	mlx_instance_t			*inst;

	figure = &data->map->character;
	inst = enabled_instances(data);
	if (inst->y)
		inst->enabled = false;
	if (figure->right->instances)
	{
		if (figure->right->instances[0].enabled == false)
			figure->right->instances[0].enabled = true;
		figure->right->instances[0].y = inst->y;
		figure->right->instances[0].x = inst->x + 5;
		data->after = data->after + 5;
	}
	else
		mlx_image_to_window(data->mlx, figure->right, inst->x + 5, inst->y);
}
