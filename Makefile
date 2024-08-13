# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 12:45:17 by joseoliv          #+#    #+#              #
#    Updated: 2024/08/13 12:59:19 by joseoliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol.a
MINILIBX_DIR = minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx.a
MINILIBX_INCLUDES = -I $(MINILIBX_DIR)

SRCS_DIR = src
SRCS = $(SRCS_DIR)/inicialization.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I $(SRCS_DIR) $(MINILIBX_INCLUDES)