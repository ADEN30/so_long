CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3 
SRCS = so_long.c set_map.c set_texture.c character.c inputs.c so_long_utils.c get_image.c set_depth.c instance.c position_player.c check_case.c key_press.c #get_next_line.c get_next_line_utils.c 
OBJS = $(SRCS:.c=.o)
LIBFT =  ./libft/libft.a
LIBS = /Users/$$USER/Documents/MLX42/build/libmlx42.a $(LIBFT) -ldl -lglfw -pthread -lm -L"/Users/$$USER/.brew/opt/glfw/lib/" 
INCLUDES = -I /Users/$$USER/Documents/MLX42/include -I ./libft
NAME = so_long

%.o : %.c
	$(CC) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -framework Cocoa -framework OpenGL -framework IOKit $(LIBS) $(LIBFT) -o $(NAME) $(OBJS)

$(LIBFT) :
	make -C libft

all : $(NAME) 

clean : 
	make clean -C libft
	rm -f $(OBJS);

fclean : clean
	make fclean -C libft
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re 
