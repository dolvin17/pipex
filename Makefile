# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 18:01:22 by dolvin17          #+#    #+#              #
#    Updated: 2023/01/30 18:05:45 by dolvin17         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =			main.c \
				
OBJS = $(SRCS:.c=.o)
CC = gcc

CC_FLAGS = -Wall -Wextra -Werror
RM_RF = rm -rf
NAME = pipex

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
all: $(NAME)
clean:
	$(RM_RF) $(OBJS)
fclean: clean
	$(RM_RF) $(NAME)
re: fclean all
.PHONY: re clean fclean all