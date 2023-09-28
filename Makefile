# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 15:04:54 by dolvin17          #+#    #+#              #
#    Updated: 2023/09/28 18:11:54 by dolvin17         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
RM = rm -rf
CFLAGS  = -Iincludes -Wall -Werror -Wextra
MAIN = main.c


SRCS =	ft_strnstr.c \
		main.c \
		ft_split.c \
		ft_strjoin.c \
		get_path.c  
		
OBJS =  ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: re clean fclean all
