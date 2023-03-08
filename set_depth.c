/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_depth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:26:15 by agallet           #+#    #+#             */
/*   Updated: 2023/03/07 13:44:15 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_image_depth(mlx_image_t *ok, int depth)
{
	int	i;

	i = 0;
	while (i < ok->count)
	{
		mlx_set_instance_depth(&(ok->instances[i]), depth);
		i++;
	}
}

void	set_all_depth(t_image_map_t *txt)
{
	int			i;
	mlx_image_t	*temp;
	int			depth;

	i = 0;
	depth = 0;
	while (i < 8)
	{
		temp = get_image_map(&(*txt), i);
		set_image_depth(temp, depth);
		if (depth < 5)
			depth++;
		i++;
	}
}
