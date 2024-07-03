# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpaic <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 16:32:16 by rpaic             #+#    #+#              #
#    Updated: 2023/11/07 16:32:19 by rpaic            ###   ########.fr        #
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
	@echo "my printf is compiling"
	
%.o: %.c ft_printf.h
	@$(COMP) $(WCHECK) -c $< -o $@
	
clean:
	@rm -f $(OBJ)
	@echo ".o removed"
fclean: clean
	@rm -f $(NAME)
	@echo "Library gone"

re: fclean all

.PHONY: all clean fclean re
