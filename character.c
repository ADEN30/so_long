/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:27:54 by agallet           #+#    #+#             */
/*   Updated: 2023/06/27 11:18:49 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	move_player(t_data_t *data)
{
	mlx_t	*mlx;

	mlx = data->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_W) && check_wall(data, &wall_hight))
		key_press_up(data);
	if (mlx_is_key_down(mlx, MLX_KEY_S) && check_wall(data, &wall_down))
		key_press_down(data);
	if (mlx_is_key_down(mlx, MLX_KEY_A) && check_wall(data, &wall_left))
		key_press_left(data);
	if (mlx_is_key_down(mlx, MLX_KEY_D) && check_wall(data, &wall_right))
		key_press_right(data);
}

int	verif_all_items(t_data_t *data)
{
	int			i;
	mlx_image_t	*items;

	items = data->map->item;
	i = 0;
	while (i < items->count)
	{
		if (items->instances[i].enabled != false)
			return (0);
		i++;
	}
	return (1);
}

void	put_string(t_data_t *data)
{
	char	*str;
	char	*nb;
	mlx_t	*mlx;

	str = NULL;
	nb = NULL;
	mlx = data->mlx;
	data->before = data->after;
	nb = ft_itoa(data->after / 64);
	str = ft_strjoin("Number of move : ", nb);
	free(nb);
	if (data->text)
		mlx_delete_image(mlx, data->text);
	data->text = mlx_put_string(mlx, str, 0, 0);
	ft_printf("%s\n", str);
	free(str);
}

void	hook(void *param)
{
	t_data_t	*data;
	mlx_t		*mlx;

	data = (t_data_t *)param;
	mlx = data->mlx;
	move_player(data);
	if (verif_all_items(data))
		data->map->door_close->enabled = false;
	open_door(data);
	take_door(data);
	if ((data->before) / 64 < data->after / 64)
		put_string(data);
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}
