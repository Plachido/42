# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plpelleg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 14:51:17 by plpelleg          #+#    #+#              #
#    Updated: 2021/03/05 14:51:19 by plpelleg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ../../libft/*.c *.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror -I. -c

all: $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) *.o
	@ranlib $(NAME)
	@make clean

bonus : $(OBJ)
	@ar rc $(NAME) *.o
	@ranlib $(NAME)
	@make clean

$(OBJ): $(SRC)
	@gcc $(FLAG) $(SRC)

clean:
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
