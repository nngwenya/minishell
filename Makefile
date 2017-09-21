# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/21 09:26:35 by nngwenya          #+#    #+#              #
#    Updated: 2017/09/21 16:49:50 by nngwenya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAG = -Wall -Wextra -Werror
FILES = echo_func.c		\
		 env_dup.c			\
		 execve_func.c		\
		 cd_func.c			\
		 set_env.c			\
		 unset_env.c		\
		 path.c				\
		 main.c				

OBJ =	 echo_func.o		\
		 env_dup.o			\
		 execve_func.o		\
		 cd_func.o			\
		 set_env.o			\
		 unset_env.o		\
		 path.o				\
		 main.o				

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(FLAG) $(FILES) libft/libft.a -o $(NAME)
	@echo "\x1b[32mCompiled $(NAME)\x1b[0m"

clean:
	@/bin/rm -f $(OBJ)
	@make clean -C libft
	@echo "\x1b[32mRemoved object files\x1b[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft
	@echo "\x1b[32mRemoved binaries\x1b[0m"

re: fclean all
