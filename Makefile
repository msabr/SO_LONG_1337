# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msabr <msabr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 10:39:34 by msabr             #+#    #+#              #
#    Updated: 2025/03/03 15:43:37 by msabr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT = Libft/libft.a

SRC_LIB = Libft/ft_atoi.c Libft/ft_bzero.c Libft/ft_calloc.c Libft/ft_isalnum.c Libft/ft_isalpha.c \
		Libft/ft_isascii.c Libft/ft_isdigit.c Libft/ft_isprint.c Libft/ft_memchr.c \
		Libft/ft_memcmp.c Libft/ft_memcpy.c Libft/ft_memmove.c Libft/ft_memset.c Libft/ft_strchr.c \
		Libft/ft_strdup.c Libft/ft_strlcat.c Libft/ft_strlcpy.c Libft/ft_strlen.c Libft/ft_strncmp.c \
		Libft/ft_strnstr.c Libft/ft_strrchr.c Libft/ft_tolower.c Libft/ft_toupper.c \
		Libft/ft_itoa.c Libft/ft_putchar_fd.c Libft/ft_putendl_fd.c Libft/ft_putnbr_fd.c Libft/ft_putstr_fd.c \
		Libft/ft_strjoin.c Libft/ft_split.c Libft/ft_strmapi.c Libft/ft_strtrim.c Libft/ft_substr.c Libft/ft_striteri.c

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
		get_next_line/get_next_line.c 
		
OBJS = $(SRCS:.c=.o)

HEADERS = mandatory/so_long.h get_next_line/get_next_line.h Libft/libft.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	
%.o: %.c $(HEADERS) $(SRC_LIB)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): $(SRC_LIB)
	@make -C Libft

clean:
	@rm -f $(OBJS)
	@make clean -C Libft
fclean: clean
	@rm -f $(NAME)
	@make fclean -C Libft

re: fclean all

.PHONY: clean
