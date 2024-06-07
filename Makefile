# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 14:20:42 by pajimene          #+#    #+#              #
#    Updated: 2024/06/07 12:33:23 by pajimene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fractol

CC 			= cc

CFLAGS 		= -Wall -Wextra -Werror

MLXFLAGS 	= -lm -lX11 -lXext

MLXLIB 		= mlx/libmlx_Linux.a 

SRC 		=	main.c \
				fractal_init.c \
				fractal_render.c \
				key_handler.c \
				mouse_handler.c \
				mlx_utils.c \
				str_utils.c \
				math_utils.c

OBJ 		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MLXLIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLXFLAGS) $(MLXLIB)

$(MLXLIB):
	make -C mlx

clean:
	rm -f $(OBJ)
	make -C mlx clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re