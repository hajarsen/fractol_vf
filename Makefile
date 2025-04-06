# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsennane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/05 23:30:43 by hsennane          #+#    #+#              #
#    Updated: 2025/04/05 23:30:45 by hsennane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = events.c fractol.c init.c math.c render.c str_utils.c
OBJ = $(SRC:.c=.o)
NAME = fractol

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
