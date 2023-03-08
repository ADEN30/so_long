CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3 
SRCS = so_long.c get_next_line.c get_next_line_utils.c set_map.c set_texture.c character.c inputs.c so_long_utils.c get_image.c set_depth.c instance.c position_player.c check_case.c key_press.c
OBJS = $(SRCS:.c=.o)
LIBS = /Users/$$USER/Documents/MLX42/build/libmlx42.a /Users/$$USER/Documents/libft/libft.a -ldl -lglfw -pthread -lm -L"/Users/$$USER/.brew/opt/glfw/lib/" 
INCLUDES = -I /Users/$$USER/Documents/MLX42/include -I /Users/$$USER/Documents/libft
NAME = so_long

%.o: %.c
	$(CC)  $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) -o $(NAME) $(OBJS) 

