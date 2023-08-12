# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flafi <flafi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 22:04:39 by flafi             #+#    #+#              #
#    Updated: 2023/04/16 03:52:03 by flafi            ###   ########.fr        #
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
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror 
CC = cc

SRCS = ft_memcmp.c ft_isascii.c ft_isdigit.c ft_isalpha.c ft_toupper.c ft_tolower.c \
	 ft_bzero.c ft_memset.c ft_isalnum.c ft_isprint.c ft_strlen.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcpy.c ft_atoi.c ft_strlcat.c ft_strlcpy.c ft_calloc.c \
	ft_strdup.c ft_memmove.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strnstr.c \
	ft_split.c 
OBJS = $(SRCS:.c=.o)

SRCS_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS_B = $(SRCS_B:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)
	echo "$(GREEN)Libft Mandatory Compiled$(DEF_COLOR)"

bonus: $(OBJS_B)
	ar rcs $(NAME) $(OBJS_B)
	echo "Libft Bonus Compiled"

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_B)
	echo "$(RED)Object Files are deleted$(DEF_COLOR)"

fclean: clean
	rm -rf $(NAME)
	echo "Everything is clean"

re: fclean all bonus

.PHONY: all clean fclean bonus re