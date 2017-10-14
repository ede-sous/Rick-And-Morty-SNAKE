# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/09 01:59:12 by ede-sous          #+#    #+#              #
#    Updated: 2017/10/12 02:06:01 by ede-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fun
GCC_FLAGS	= gcc -Wall -Werror -Wextra -Weverything -g -ltermcap `SDL2-config --cflags --libs` -lSDL2_image -lSDL2_ttf
LIB			= ./Libft/libft.a
INCLUDES	= -I./includes
INC			= ./includes/header.h ./includes/const_vars.h 

SRCS_DIR	= ./sources/
SRCS_FILES	= main.c init_position.c snake_movement.c init_animals.c \
			  snake_details.c menu.c boosts.c
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS		= $(SRCS:.c=.o)

all : lib $(NAME)

lib :
	@make -C ./Libft/

$(NAME): $(OBJS) $(INC) Makefile
	@$(GCC_FLAGS) -o $(NAME) $(OBJS) $(INCLUDES) -L./Libft/ -lft
	@echo "        \033[42m $(NAME) claiming for PoWa !\033[0m"

%.o : %.c
	@gcc -c -o $@ $< $(INCLUDES)

clean :
	@make -C ./Libft/ clean
	@rm -rf $(OBJS)
	@echo "            \033[92m Mission completed."
	@echo "            All Objects are dead.\033[0m"

fclean : clean
	@make -C ./Libft/ fclean
	@rm -rf $(NAME)
	@echo " \033[95m Ups... My fluffy weapon killed $(NAME) :x\033[0m"

re: fclean all
