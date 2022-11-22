# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 19:14:21 by ccantale          #+#    #+#              #
#    Updated: 2022/11/22 00:57:21 by ccantale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @gcc
CFLAGS = -g #-I -Wall -Werror -Wextra
READLINE_FLAGS = -L/usr/include -lreadline -L$$HOME/.brew/opt/readline/lib -I $$HOME/.brew/opt/readline/include/readline

INCLUDES = $(shell find . -name "*.h" -print)

OBJS_DIR = bin
OBJS_NOPREFIX = $(shell find . -name "*.c" -print | sed 's/\.c/\.o/g' | sed 's/\.\///')# last cmd removes ./ at the beginning of each file
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_NOPREFIX))

NAME = minishell

all: .BUILD

bonus: .BUILD

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(READLINE_FLAGS) $(OBJS) -o $(NAME)
	@printf "\033[1m\033[32mMinishell Compiled!\n"
	@echo "\033[0;37m"

#
#	this rule compiles sources in <path>.c and puts them in <obj_dir>/<path>.o
#
#
$(shell echo $(OBJS_DIR))/%.o: %.c $(INCLUDES)#$(wildcard $(<D)/*.h)------this recompiles only for headers in the same folder!
	@mkdir -p '$(@D)'
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	@printf "removing Object files...\n"
	@/bin/rm -f $(OBJS)
	@printf "\033[0;35mObject files removed!\n"
	@echo "\033[0;37m"

fclean: clean
	@printf "removing program executable...\n"
	@/bin/rm -f ./minishell
	@/bin/rm -rf bin
	@printf "\033[0;35mExecutable removed!\n"
	@echo "\033[0;37m"

re: fclean all

git:
	git add .
	git commit -m minishell
	git push

.BUILD:
	@printf "\033[1m\033[33mMaking Project...\033[0m\n"
	@$(MAKE) $(NAME)
