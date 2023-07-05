/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:58:49 by agallet           #+#    #+#             */
/*   Updated: 2023/06/27 10:44:11 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Set Map */
int	set_map(char **map, t_data_t *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (map[i])
	{
		x = 0;
		j = 0;
		while (map[i][j])
		{
			if (find_txt(map[i][j], data, &x, &y))
				mlx_image_to_window(data->mlx,
					find_txt(map[i][j], data, &x, &y), x, y);
			x += 64;
			j++;
		}
		i++;
		y += 64;
	}
	set_all_depth(data->map);
	return (1);
}

int	check_format(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (!ft_strncmp(&str[i], ".ber", ft_strlen(&str[i])))
		return (1);
	else
		return (0);
}

/* Recover the map */

char	**save_map(char *file, int length, t_data_t *data)
{
	int		fd;
	int		i;
	char	**table;
	char	*str;

	i = 0;
	table = malloc(sizeof(char *) * (length + 1));
	if (!table)
		return (NULL);
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	data->width = 64 * (ft_strlen(str) - 1);
	while (str)
	{
		table[i++] = str;
		str = get_next_line(fd);
	}
	close(fd);
	table[i] = NULL;
	return (table);
}

char	**set_table_map(char *file, t_data_t *data)
{
	char	**table;
	char	*str;
	int		fd;
	int		length;

	length = 0;
	str = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		length++;
	}
	if (length == 0)
		return (0);
	data->height = 64 * length;
	close(fd);
	table = save_map(file, length, data);
	return (table);
}
