/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:07:25 by agallet           #+#    #+#             */
/*   Updated: 2023/06/26 10:34:08 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	clear_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	set_data(t_data_t *data, mlx_t *mlx, t_image_map_t *txt)
{
	data->after = 0;
	data->before = 0;
	data->mlx = mlx;
	all_texture(txt, mlx);
	data->map = txt;
}

int	check_map(char **map)
{
	int	*item;
	int	*xy;

	xy = coordp(map);
	if (!xy)
	{
		write(1, "Error\nThere is not start in the map\n", 37);
		return (0);
	}
	item = count_item(map);
	if (!floodfill(xy[0], xy[1], map, item) || !item[0]
		|| item[0] != item[1] || item[2] != 1 || item[3] != 1)
	{
		put_error(item);
		free(item);
		free(xy);
		item = NULL;
		xy = NULL;
		return (0);
	}
	free(item);
	free(xy);
	return (1);
}

int	errors_file(char *path, t_data_t *data)
{
	char	**map;

	map = set_table_map(path, data);
	if (!map)
	{
		write(1, "Error\nfile not find\n", 21);
		return (0);
	}
	if (!check_format(path) || !check_line(map))
	{	
		clear_tab(map);
		write(1, "Error\nbad format\n", 18);
		return (0);
	}
	if (!check_map(map))
	{
		clear_tab(map);
		return (0);
	}	
	clear_tab(map);
	return (1);
}

int	main(int argc, char **argv)
{
	mlx_t			*mlx;
	t_image_map_t	txt;
	t_data_t		data;
	char			**map;

	map = NULL;
	if (argc != 2)
		return (0);
	if (!errors_file(argv[argc - 1], &data))
		return (EXIT_FAILURE);
	map = set_table_map(argv[argc - 1], &data);
	mlx = mlx_init(data.width, data.height, "MLX42", true);
	if (!mlx)
		return (EXIT_FAILURE);
	set_data(&data, mlx, &txt);
	set_map(map, &data);
	clear_tab(map);
	mlx_loop_hook(data.mlx, &hook, &data);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	system("leaks so_long");
	return (EXIT_SUCCESS);
}
