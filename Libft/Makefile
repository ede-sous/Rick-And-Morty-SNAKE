# **************************************************************************** #
#                                                                              #
#
#
#
#
#:::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ede-sous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 19:01:52 by ede-sous          #+#    #+#              #
#    Updated: 2016/12/14 22:17:48 by ede-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =  ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
		ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
		ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
		ft_putstr.c ft_putnbr.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putnbr_fd.c ft_putendl_fd.c ft_count.c ft_split_whitespaces.c \
		ft_isval.c ft_strrev.c ft_epur.c ft_strtolower.c ft_strtoupper.c \
		get_next_line.c ft_doubleread.c ft_strendl.c ft_doubledup.c \
		ft_doublestr.c ft_doublepur.c ft_sortit.c ft_putnbrl.c ft_dtoo.c \
		ft_triplestr.c ft_triplendl.c ft_takeout.c ft_doublelen.c \
		ft_doublenew.c ft_triplendl_fd.c ft_fullblanks.c ft_strcut.c \
		ft_sortrev.c ft_doubledel.c ft_triplestr_fd.c ft_doublefree.c

OBJS = $(SRCS:.c=.o)

FG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@gcc $(FG) -c $(SRCS) -I.
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[1;32m$(NAME) is now Among Us with all his Binary Files\033[0m"

%.o: %.c
	@gcc -c -o $@ $< -I.

clean:
	@rm -rf $(OBJS)
	@echo "\033[1;35mBinary Files shall fall with the Power of the Void !!\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "    \033[1;31mR.I.P our fellow Library ... $(NAME) ...\033[0m"

re: fclean all
