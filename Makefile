# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msabr <msabr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 10:39:34 by msabr             #+#    #+#              #
#    Updated: 2025/02/19 11:30:18 by msabr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
LIBFT = Libft/libft.a

SRCS =	mandatory/functions_game.c \
		mandatory/functions_images.c \
		mandatory/functions_keypress.c \
		mandatory/functions_map_check.c \
		mandatory/functions_map_explore.c \
		mandatory/functions_map_view.c \
		mandatory/functions_map.c \
		mandatory/functions_parssing.c \
		mandatory/functions_window.c \
		mandatory/main.c \
		get_next_line/get_next_line.c \
		
OBJS = $(SRCS:.c=.o)

HEADERS = mandatory/so_long.h  get_next_line/get_next_line.h Libft/libft.h

all: $(NAME)

%.o: %.c mandatory/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)


$(LIBFT):
	@make -C Libft

clean:
	@rm -f $(OBJS)
	@make clean -C Libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C Libft

re: fclean all

.PHONY: clean fclean re all
