# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/02 13:17:35 by reerikai          #+#    #+#              #
#    Updated: 2025/02/10 13:46:34 by reerikai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

LIBFT	= ./libft/libft.a
LIBPATH	= ./libft

MLX		= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBMLX	= ./MLX42

HEADERS	= -I $(LIBPATH) -I $(LIBMLX)/include

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -g -I libft -Wunreachable-code -Ofast

SRCS	= fdf.c

OBJS	= $(SRCS:.c=.o)

RM		= rm -rf

all:	libmlx	$(NAME)

libmlx:
		@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJS) $(LIBFT)
			$(CC) $(OBJS) $(MLX) $(HEADERS) $(LIBFT) -o $(NAME)

$(LIBFT): $(LIBPATH)
				@$(MAKE) -C $^

%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)
		printf "Compiling: $(notdir $<)"

clean:
		$(RM) $(OBJS)
		$(MAKE) -C $(LIBPATH) clean

fclean: clean
		$(RM) $(NAME)
		$(MAKE) -C $(LIBPATH) fclean

re: fclean all
