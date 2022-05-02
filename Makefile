NAME = cub_3d

SRCS = cub_3d.c gnl/get_next_line.c gnl/get_next_line_utils.c ft_strncmp.c ft_atoi.c functions_1.c functions_2.c functions_3.c functions_4.c auf.c  1.c             11.c            13.c            3.c             5.c             7.c             9.c  10.c            12.c            2.c             4.c             6.c             8.c

INCLUDE = cub.h

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX = -framework OpenGL -framework AppKit -lmlx

LIBA = libft/libft.a

all : $(NAME)

%.o: %.c $(SRCS)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJS) $(INCLUDE)
	$(CC) $(LIBA) $(CFLAGS) $(OBJS) -I./include $(MLX) -o $(NAME)

bonus : $(OBJS) $(INCLUDE)
	$(CC) $(LIBA) $(CFLAGS) $(OBJS) -I./include $(MLX) -o cub_3D_bonus

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean re all