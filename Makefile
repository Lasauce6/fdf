# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 16:06:00 by rbaticle          #+#    #+#              #
#    Updated: 2024/12/19 16:49:39 by rbaticle         ###   ########.fr        #
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
SRCS_NAMES = main.c
SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAMES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LFT):
	@make -C $(LFT_DIR)

$(LIBX):
	@make -C $(LIBX_DIR)

$(NAME): $(LFT) $(LIBX) $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS) -L $(LFT_DIR) -lft -I $(INCLUDES) -L $(LIBX_DIR) -lmlx -I $(LIBX_DIR) -o $(NAME)

debug: $(LFT) $(LIBX) $(HEADERS)
	$(CC) $(CFLAGS) -g $(SRCS) -L $(LFT_DIR) -lft -I $(INCLUDES) -L $(LIBX_DIR) -lmlx -I $(LIBX_DIR) -o $(NAME)

fsanitize: $(LFT) $(LIBX) $(HEADERS)
	$(CC) $(CFLAGS) -g -fsanitize=address $(SRCS) -L $(LFT_DIR) -lft -I $(INCLUDES) -L $(LIBX_DIR) -lmlx -I $(LIBX_DIR) -o $(NAME)

clean:
	$(RM) $(OBJS)
	@make clean -C $(LFT_DIR)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LFT_DIR)
	@make clean -C $(LIBX_DIR)

re: fclean all

.PHONY: clean fclean re fsanitize debug
