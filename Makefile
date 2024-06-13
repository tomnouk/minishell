# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 20:49:57 by aeid              #+#    #+#              #
#    Updated: 2024/06/13 16:48:13 by aeid             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
PFLAGS = -L./Printft -lftprintf
LFLAGS = -L./Libft -lft
RM = rm -f
PRINT_DIR = ./Printft
LIBFT_DIR = ./Libft

H_SRC = lexer.h minishell.h
H_DIR = headers/
H_PATH = $(addprefix $(H_DIR), $(H_SRC))

M_SRC = main.c
M_OBJ = $(M_SRC:.c=.o)

L_SRC = lexer.c word_token.c utils.c meta_token.c special_token.c \
		meta_cases.c
L_DIR = Lexer/
L_PATH = $(addprefix $(L_DIR), $(L_SRC))
L_OBJ = $(L_PATH:.c=.o)

%.o: %.c $(H_PATH) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(M_OBJ) $(L_OBJ)
	make -C $(PRINT_DIR) --no-print-directory
	make -C $(LIBFT_DIR) --no-print-directory
	$(CC) $(M_OBJ) $(L_OBJ) $(PFLAGS) $(LFLAGS) -lreadline -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(M_OBJ)
	$(RM) $(L_OBJ)
	$(RM) $(wildcard $(PRINT_DIR)/*.o)
	$(RM) $(wildcard $(LIBFT_DIR)/*.o)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(PRINT_DIR)/libftprintf.a
	$(RM) $(LIBFT_DIR)/libft.a

re: fclean all

.PHONY: all clean fclean re