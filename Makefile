SRCS = src/so_long.c src/map.c src/map_utils.c src/map_utils2.c src/mlx_utils.c get_next_line/get_next_line.c

OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -f
LIBFT = libft
MLX = mlx
CFLAGS = -g -Wall -Wextra -Werror -I$(HEADER) -I$(LIBFT) -I$(MLX)
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
HEADER = inc

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) -C $(LIBFT)
		$(MAKE) -C $(MLX)
		$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT) -lft

clean:
		$(RM) $(OBJS) $(BONUS_OBJS) $(LIBFT)/*.o

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus 
