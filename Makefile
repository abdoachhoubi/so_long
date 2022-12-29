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

BSRC = ${addprefix bonus/, check.c controllers.c image.c controls.c} \
		${addprefix bonus/, map.c setup.c utils.c win.c so_long.c} \
		${addprefix bonus/, valid_path.c valid_path_utils.c counts.c}

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX = -g -framework OpenGL -framework AppKit -L./mlx -lmlx

all: ${NAME}

${NAME}: ${LIBFT} ${PRINTF}
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
