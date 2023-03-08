/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:35:02 by agallet           #+#    #+#             */
/*   Updated: 2023/03/07 13:44:15 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_instance_t	*inst_desable(mlx_image_t *img)
{
	int	i;

	i = 0;
	while (i < img->count)
	{
		if (img->instances[i].enabled == true)
			return (&img->instances[i]);
		i++;
	}
	return (NULL);
}

mlx_instance_t	*enabled_instances(t_data_t *data)
{
	mlx_image_t	*img;
	int			i;

	i = 4;
	while (i < 8)
	{
		img = get_image_map(data->map, i);
		if (inst_desable(img))
			return (inst_desable(img));
		i++;
	}
	return (NULL);
}
