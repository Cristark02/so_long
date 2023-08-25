# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmita <mmita@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 17:01:26 by mmita             #+#    #+#              #
#    Updated: 2023/08/25 19:29:34 by mmita            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalnum.c	\
ft_isalpha.c		\
ft_isascii.c		\
ft_isdigit.c		\
ft_isprint.c		\
ft_strlen.c			\
ft_memset.c			\
ft_bzero.c			\
ft_memcpy.c			\
ft_memmove.c		\
ft_strlcpy.c		\
ft_strlcat.c		\
ft_toupper.c		\
ft_tolower.c		\
ft_strchr.c			\
ft_strrchr.c		\
ft_strncmp.c		\
ft_memchr.c			\
ft_memcmp.c			\
ft_strnstr.c		\
ft_atoi.c			\
ft_calloc.c 		\
ft_strdup.c 		\
ft_substr.c 		\
ft_strjoin.c 		\
ft_strtrim.c 		\
ft_split.c 			\
ft_itoa.c 			\
ft_strmapi.c 		\
ft_striteri.c 		\
ft_putchar_fd.c 	\
ft_putstr_fd.c 		\
ft_putendl_fd.c 	\
ft_putnbr_fd.c		\
ft_strenlarge.c 	\
ft_countchar.c		\
ft_strrncmp.c		\
\
../get_next_line/main.c 				\
../get_next_line/get_next_line.c 		\
../get_next_line/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

BONUS =	ft_lstnew_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c \
ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c \
ft_lstclear_bonus.c \
ft_lstiter_bonus.c \
ft_lstmap_bonus.c

BONUS_OBJS = $(BONUS:.c=.o)

BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

shell := /bin/zsh

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar crs
SHELL := /bin/zsh

$(NAME): $(OBJS) $(BONUS_OBJS)
	@$(AR) $@ $^
	@zsh -c "echo -n ·"

%.o: %.c
	@zsh -c "echo -n ━"
	@$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
	@$(RM) $(NAME)		
	@echo "$(RED)$(BOLD)Libft+ Limpio$(RESET)"

re:	fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS)  $(BONUS_OBJS)

.PHONY:	all clean fclean re bonus

# gcc src/*.c libs/Libft+/libft.a libs/MLX42/libmlx42.a -lglfw -L "/Users/$USER/.brew/opt/glfw/lib/"