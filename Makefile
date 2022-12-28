SRC = ${addprefix src/, check.c controllers.c image.c controls.c} \
		${addprefix src/, map.c setup.c utils.c win.c so_long.c} \
		${addprefix src/, valid_path.c valid_path_utils.c}

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX = -g -framework OpenGL -framework AppKit -L./mlx -lmlx

all: ${NAME}

${NAME}: ${LIBFT} ${PRINTF}
		@echo ${SRC}
		@${CC} ${CFLAGS} ${SRC} ${LIBFT} ${PRINTF} ${MLX} -o ${NAME}

${LIBFT}:
		@make -C libft

${PRINTF}:
		@make -C ft_printf

clean:
		@make clean -C libft
		@make clean -C ft_printf

fclean: clean
		@${RM} ${NAME}
		@make fclean -C libft
		@make fclean -C ft_printf

re: fclean all
