# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 12:45:17 by joseoliv          #+#    #+#              #
#    Updated: 2024/08/13 16:09:56 by joseoliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
OS		= $(shell uname)

#dir
OBJS_DIR = ./obj
SRCS_DIR = ./src
INCL_DIR = ./includes

SRCS = $(SRCS_DIR)/inicialization.c
OBJS = $(SRCS:.c=.o)


CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I $(SRCS_DIR) $(MINILIBX_INCLUDES) $(LIBFT_INCLUDES)

#lib to link
LIBS = -L$(MINILIBX_DIR) -lmlx -L$(LIBFT_DIR) -lft -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(OBJS) $(LIBS) $(INCLUDES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) -s

$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_DIR) -s

clean:
	@rm -rf $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean -s
	@$(MAKE) -C $(MINILIBX_DIR) clean -s

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean -s
	@$(MAKE) -C $(MINILIBX_DIR) fclean -s

re: fclean all