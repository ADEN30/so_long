/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:23:39 by agallet           #+#    #+#             */
/*   Updated: 2023/06/26 10:44:33 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	mlx_image_t	*set_images(mlx_t *mlx, char *path)
{
	mlx_texture_t	*temp;
	mlx_image_t		*img;

	temp = mlx_load_png(path);
	img = mlx_texture_to_image(mlx, temp);
	mlx_delete_texture(temp);
	return (img);
}

/* Set texture */
void	all_texture(t_image_map_t *txt, mlx_t *mlx)
{
	txt->floor = set_images(mlx, "./png/FLOOR_1A.png");
	txt->wall = set_images(mlx, "./png/BRICK_2a.png");
	txt->item = set_images(mlx, "./png/SUPPORT_4A.png");
	txt->door = set_images(mlx, "./png/HEDGE_1C.png");
	txt->door_close = set_images(mlx, "./png/HEDGE_1A.png");
	txt->character.down = set_images(mlx, "./png/figure2_down.png");
	txt->character.hight = set_images(mlx, "./png/figure2_hight.png");
	txt->character.left = set_images(mlx, "./png/figure2_left.png");
	txt->character.right = set_images(mlx, "./png/figure2_right.png");
}

mlx_image_t	*get_image_character(t_image_map_t *txt, int i)
{
	if (i == 4)
		return (txt->character.down);
	else if (i == 5)
		return (txt->character.hight);
	else if (i == 6)
		return (txt->character.left);
	else
		return (txt->character.right);
}

mlx_image_t	*get_image_map(t_image_map_t *txt, int i)
{
	if (i == 0)
		return (txt->floor);
	else if (i == 1)
		return (txt->wall);
	else if (i == 2)
		return (txt->item);
	else if (i == 3)
		return (txt->door);
	else
		return (get_image_character(&(*txt), i));
}
