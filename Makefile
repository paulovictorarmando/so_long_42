# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parmando <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 08:10:20 by parmando          #+#    #+#              #
#    Updated: 2024/09/18 08:10:23 by parmando         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c\
		ft_free.c\
		get_map.c\
		set_map.c\
		set_datas.c\
		render.c\
		move_player.c


OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX = -L./mlx -lmlx -lX11 -lXext

MLX_DIR = ./mlx

LIBFT_DIR = ./libft

MLX_LIB = $(MLX_DIR)/libmlx_linux.a

LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME): ${OBJS}
	@ ${CC} ${CFLAGS} ${OBJS} -o ${NAME} -I. ${MLX} ${LIBFT}

$(MLX_LIB):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f ${OBJS}

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	rm -f ${NAME}

re: fclean all
