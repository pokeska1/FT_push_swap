# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 16:25:10 by jmarian           #+#    #+#              #
#    Updated: 2021/07/21 03:34:17 by jmarian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = 		gcc

FLAG =		 -g -Wall -Wextra -Werror

OBJC =		$(SRCS:.c=.o)

NAME	=	push_swap
				
SRCS	=	push_swap.c								\
			soft/soft.c								\
			soft/soft_two.c							\
			soft/soft_atoi.c						\
			soft/soft_three.c						\
			engine/pa_pb.c							\
			engine/sa_sb_ss.c						\
			engine/parser.c							\
			engine/some_magick_int.c				\
			engine/sort_mor_one_hundred.c			\
			checker/is_it_valid.c					\

RM		=	rm -f

all: 		$(NAME) push_swap.h

$(NAME):	$(OBJC)
			$(CC) $(FLAG) $(OBJC) -o $(NAME)

%.o:	%.c
			$(CC) -c $(FLAG) $< -o $@

clean:
			$(RM) $(OBJC)

fclean:		clean
			$(RM) $(NAME)
		
re: 		fclean all clean

.PHONY:		all clean fclean re
