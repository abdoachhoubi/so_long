# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 12:34:19 by aachhoub          #+#    #+#              #
#    Updated: 2022/10/22 12:34:21 by aachhoub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_putchar ft_putstr ft_putnbr ft_putnbr_u \
      ft_putnbr_base ft_print_memory ft_printf
OBJ = $(SRC:=.o)
NAME = libftprintf.a
LIBR = ar -rc
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

%.o:%.c
	@$(CC) $(CFLAGS) -c $<

all : $(NAME)

$(NAME): $(OBJ)
	@$(LIBR) $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
