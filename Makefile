# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 16:48:44 by aachhoub          #+#    #+#              #
#    Updated: 2022/12/28 16:48:45 by aachhoub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ${addprefix src/, check.c controllers.c image.c controls.c} \
		${addprefix src/, map.c setup.c utils.c win.c so_long.c} \
		${addprefix src/, valid_path.c valid_path_utils.c}

BSRC = ${addprefix src/, valid_path_utils.c setup.c utils.c win.c valid_path.c} \
		${addprefix bonus/, counts.c map.c controls.c image.c} \
		${addprefix bonus/, check.c controllers.c so_long.c}

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a

NAME = so_long

CC = cc

CFLAGS = 

MLX = ./minilibx-macos/libmlx.a -lmlx -framework OpenGL -framework AppKit -I minilibx-macos -L minilibx-macos

MLXLINUX = ./minilibx-linux/libmlx.a -lXext -lX11 -lm

all: ${NAME}

linux: ${MLXLINUX} ${LIBFT} ${PRINTF}
		@echo "Compiled so_long"
		@${CC} ${CFLAGS} ${BSRC} ${LIBFT} ${PRINTF} ${MLXLINUX} -o ${NAME}

${NAME}: ${LIBFT} ${PRINTF} ${MLX}
		@echo "Compiled so_long"
		@${CC} ${CFLAGS} ${SRC} ${LIBFT} ${PRINTF} ${MLX} -o ${NAME}

bonus: ${LIBFT} ${PRINTF}
		@rm -rf ${NAME}
		@echo "Compiled so_long (bonus)"
		@${CC} ${CFLAGS} ${BSRC} ${LIBFT} ${PRINTF} ${MLX} -o ${NAME}

${LIBFT}:
		@echo "Compiled Libft"
		@make -C libft

${PRINTF}:
		@echo "Compiled ft_printf"
		@make -C ft_printf

${MLX}:
		@echo "Compiled Minilibx"
		@make -C minilibx-linux

clean:
		@echo "Deleted Object Files"
		@make clean -C libft
		@make clean -C ft_printf

fclean: clean
		@echo "Deleted Libraries and so_long"
		@${RM} ${NAME}
		@make fclean -C libft
		@make fclean -C ft_printf

re: fclean all
