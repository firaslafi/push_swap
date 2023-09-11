# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flafi <flafi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 03:09:57 by flafi             #+#    #+#              #
#    Updated: 2023/05/12 01:48:28 by flafi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;32m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

.SILENT:
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror 
CC = cc

SRCS = ft_printf.c ft_format.c ft_more_format.c ft_fn.c
OBJS = $(SRCS:.c=.o)



$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS) $(LIBFT)
	echo "$(GREEN)Printf Compiled$(DEF_COLOR)"

all: $(NAME)



clean:
	rm -f $(OBJS)
	echo "$(RED)Object Files are deleted$(DEF_COLOR)"

fclean: clean
	rm -rf $(NAME)
	echo "Everything is clean"

re: fclean all

.PHONY: all clean fclean re