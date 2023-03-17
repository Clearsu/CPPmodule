# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 17:14:19 by jincpark          #+#    #+#              #
#    Updated: 2023/03/17 16:37:36 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harl

CC = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror
DFLAGS = -fsanitize=address

RM = rm -f

SRCS = main.cpp

ifdef IF_DEBUG
	$(FLAGS) += $(DFLAGS)
endif

$(NAME) : $(SRCS)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) -I .

all : $(NAME)

clean :
	$(RM) $(NAME)

re :
	$(MAKE) clean
	$(MAKE) all

debug :
	$(MAKE) IF_DEBUG=1
