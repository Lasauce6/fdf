# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 16:06:00 by rbaticle          #+#    #+#              #
#    Updated: 2025/01/03 13:14:27 by rbaticle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = fdf
RM = rm -fr

LFT_DIR = ./libft/
LFT = $(addprefix $(LFT_DIR), libft.a)
LIBX_DIR = ./minilibx-linux/
LIBX = $(addprefix $(LIBX_DIR), libmlx.a)

INCLUDES = ./includes/
HEADERS_NAMES = fdf.h
HEADERS = $(addprefix $(INCLUDES), $(HEADERS_NAMES))
SRCS_NAMES = utils.c error.c parsing.c \
			 free.c init_data.c init_mlx.c \
			 draw.c handle_keypress.c bresenham.c \
			 colors.c transformation.c rotation.c
SRCS_DIR = ./srcs/
SRCS = main.c ./ft_printf/ft_printf.c $(addprefix $(SRCS_DIR), $(SRCS_NAMES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LFT):
	@make -C $(LFT_DIR)

$(LIBX):
	@make -C $(LIBX_DIR)

$(NAME): $(LFT) $(LIBX) $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS) -L $(LFT_DIR) -lft -I $(INCLUDES) -L $(LIBX_DIR) -lX11 -lXext -lmlx -lm -o $(NAME)

debug: $(LFT) $(LIBX) $(HEADERS)
	$(CC) $(CFLAGS) -g $(SRCS) -L $(LFT_DIR) -lft -I $(INCLUDES) -L $(LIBX_DIR) -lX11 -lXext -lmlx -lm -o $(NAME)

fsanitize: $(LFT) $(LIBX) $(HEADERS)
	$(CC) $(CFLAGS) -g -fsanitize=address $(SRCS) -L $(LFT_DIR) -lft -I $(INCLUDES) -L $(LIBX_DIR) -lX11 -lXext -lmlx -lm -o $(NAME)

clean:
	$(RM) $(OBJS)
	@make clean -C $(LFT_DIR)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LFT_DIR)
	@make clean -C $(LIBX_DIR)

re: fclean all

.PHONY: clean fclean re fsanitize debug
