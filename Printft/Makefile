# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 16:32:16 by rpaic             #+#    #+#              #
#    Updated: 2024/07/15 18:31:19 by anomourn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

COMP = cc
WCHECK = -Wall -Wextra -Werror

CFILES = ft_printf.c ft_putadress.c ft_putchar.c ft_unbr_base.c\
	ft_putnbr_base.c ft_putstr.c ft_unsigned.c

OBJ = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\e[0;35m ----> PRINTF compliled with succes\e[0;m"
	
%.o: %.c ft_printf.h
	@$(COMP) $(WCHECK) -c $< -o $@
	
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
	@echo "Library gone"

re: fclean all

.PHONY: all clean fclean re

.SILENT:
