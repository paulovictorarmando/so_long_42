# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parmando <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 15:19:55 by parmando          #+#    #+#              #
#    Updated: 2024/05/23 15:20:07 by parmando         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memmove.c \
	ft_memcpy.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_get_next_line.c\
	ft_printf.c\
	ft_puts.c \
	ft_puthex.c\
	ft_putnbr.c\
	ft_putptr.c\
	ft_puthe_m.c\
	ft_putunbr.c

NAME = libft.a
	
OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): ${OBJS}
	@ar rcs ${NAME} ${OBJS}

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
re: fclean all 
