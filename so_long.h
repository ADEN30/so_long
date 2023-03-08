/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:02:59 by agallet           #+#    #+#             */
/*   Updated: 2023/03/07 13:44:43 by agallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "MLX42/MLX42.h"
# include <memory.h>
# include "get_next_line.h"
# include "libft.h"
# define WIDTH 832
# define HEIGHT 320

typedef struct sl_image_character
{
	mlx_image_t	*down;
	mlx_image_t	*hight;
	mlx_image_t	*left;
	mlx_image_t	*right;
}	t_image_character_t;

typedef struct sl_txt_map
{
	mlx_image_t				*floor;
	mlx_image_t				*wall;
	mlx_image_t				*item;
	mlx_image_t				*door;
	mlx_image_t				*door_close;
	t_image_character_t		character;
}	t_image_map_t;

typedef struct sl_data
{
	int				height;
	int				width;
	mlx_t			*mlx;
	t_image_map_t	*map;
	int				after;
	int				before;
	mlx_image_t		*text;
}	t_data_t;

/* So_long */
void			clear_tab(char **str);

/* Set_texture */
mlx_image_t		*find_txt(char c, t_data_t *data, int *x, int *y);
void			set_character(t_data_t *data, int *x, int *y);

/* Set_map */
int				set_map(char **map, t_data_t *data);
char			**set_table_map(char *fd, t_data_t *data);
mlx_image_t		*get_image_map(t_image_map_t *txt, int i);
int				check_format(char *str);

/* Inputs */
int				floodfill(int x, int y, char **str, int *item);
int				*count_item(char **str);
void			put_error(int *item);

/* character */
void			hook(void *param);

/* So_long_utils */
int				*coordp(char **str);
int				check_line(char **str);

/* Get_image */
void			all_texture(t_image_map_t *txt, mlx_t *mlx);
mlx_image_t		*get_image_character(t_image_map_t *txt, int i);
mlx_image_t		*get_image_map(t_image_map_t *txt, int i);

/* Set_depth */
void			set_image_depth(mlx_image_t *ok, int depth);
void			set_all_depth(t_image_map_t *txt);

/* Instance */
mlx_instance_t	*inst_desable(mlx_image_t *img);
mlx_instance_t	*enabled_instances(t_data_t *data);

/* Position_player */
int				wall_right(mlx_instance_t wall,
					mlx_instance_t figure, t_data_t *data);
int				wall_left(mlx_instance_t wall,
					mlx_instance_t figure, t_data_t *data);
int				wall_hight(mlx_instance_t wall,
					mlx_instance_t figure, t_data_t *data);
int				wall_down(mlx_instance_t wall,
					mlx_instance_t figure, t_data_t *data);

/* Check_case */
int				check_wall(t_data_t *data,
					int (*f)(mlx_instance_t, mlx_instance_t, t_data_t *));
int				check_items(t_data_t *data,
					int (*f)(mlx_instance_t, mlx_instance_t, t_data_t *));
int				check_door(t_data_t *data,
					int (*f)(mlx_instance_t, mlx_instance_t, t_data_t *));
void			open_door(t_data_t *data);
void			take_door(t_data_t *data);

/* Key_press */
void			key_press_up(t_data_t *data);
void			key_press_down(t_data_t *data);
void			key_press_left(t_data_t *data);
void			key_press_right(t_data_t *data);
#endif
