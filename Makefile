# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 15:24:17 by joseoliv          #+#    #+#              #
#    Updated: 2024/10/09 03:34:57 by joseoliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -g

MINILIBX_DIR = libs/minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx.a

LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = libs/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

CFLAGS = -Wextra -Wall -Werror
LDFLAGS = $(LIBFT) $(MINILIBX) -lX11 -lXext -lm
SRCS =	src/main.c src/fractol_init/init.c src/helper_funcs/math_utils.c src/events/hooks.c \
		src/fractol_render/render_fern.c src/helper_funcs/math_utils2.c src/main_helper.c \
		src/events/hooks_bonus.c src/fractol_render/render_mandel_julia.c src/helper_funcs/list_utils.c
OBJS = $(SRCS:.c=.o)
NAME = fractol

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) -s

$(MINILIBX):
	@make -C $(MINILIBX_DIR) -s

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR) -s

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR) -s

re: fclean all
