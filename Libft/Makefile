# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 16:46:45 by rpaic             #+#    #+#              #
#    Updated: 2024/07/15 18:43:22 by anomourn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror 

SRC = $(filter-out %_bonus.c,$(foreach D, . ,$(wildcard $(D)/*.c)))

BONUS_SRC = $(foreach D, . , $(wildcard $(D)/*_bonus.c))
OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(BONUS_OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\e[0;35m ----> LIBFT compliled with succes\e[0;m"

bonus:	$(BONUS_OBJ)
	@ar rc $(NAME) $(BONUS_OBJ)
	@ranlib $(NAME)
	@echo "LIBFT compliled with BONUS succes"

%.o: %.c libft.h
	@$(CC) $(CFLAGS) -c $< -o $@

test: libft.a
	@$(CC) $(CFLAGS) $(p) -L. -lft -lbsd

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)
	@echo "\e[0;32m$< ----> $@\e[0;m"
	
fclean: clean
	@rm -f $(NAME)
	@echo "Libreria rimossa."

re: fclean all

.PHONY: all clean fclean re bonus

.SILENT:
