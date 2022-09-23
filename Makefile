# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccantale <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 19:14:21 by ccantale          #+#    #+#              #
#    Updated: 2022/09/23 16:07:31 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=		gcc
FLAGS	=		-Wall -Wextra -Werror


NAME	=		Minishell

FILES	=		main.c \
				read/read.c \
				read/prompt/prompt.c \
				utils/string_utils/ft_strlen.c \
				utils/string_utils/ft_strjoin.c \
				read/prompt/prompt_utils/prompt_utils.c

OBJDIR	=		obj

OBJ		=		$(FILES:%.c=$(OBJDIR)/%.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(OBJDIR)/%.o: %.c
	mkdir -p obj
	$(CC) $(FLAGS) -g -c $< -o $@

clean:
	rm -r obj

fclean:
	rm $(NAME)

re: $(NAME) fclean
	rm -r obj
	make

go:
	make
	./philo 4 420 200 200

l:
	make
	leaks --atExit -- ./philo 4 420 200 200
	
seg:
	make
	lldb ./philo -- 4 420 200 200

.PHONY: all clean fclean re go l seg
