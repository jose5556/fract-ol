# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cereais <cereais@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 15:24:17 by joseoliv          #+#    #+#              #
#    Updated: 2025/04/16 15:02:32 by cereais          ###   ########.fr        #
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
		src/events/hooks_bonus.c src/fractol_render/render_mandel_julia.c \
		src/helper_funcs/list_utils.c src/events/hook_exit.c
OBJS = $(SRCS:.c=.o)
NAME = fractol

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.c | $(MINILIBX)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) -s

$(MINILIBX):
	@if [ ! -d "$(MINILIBX_DIR)" ]; then \
		echo "MiniLibX not found, cloning..."; \
		git clone https://github.com/42Paris/minilibx-linux.git $(MINILIBX_DIR); \
	fi
	@make -C $(MINILIBX_DIR) || true
	@test -f $(MINILIBX) || (echo "MiniLibX build failed!" && exit 1)

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR) -s

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR) -s

re: fclean all
