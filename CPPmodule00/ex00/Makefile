# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 18:17:02 by jincpark          #+#    #+#              #
#    Updated: 2023/03/10 18:58:15 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror

RM = rm -f

SRCS = megaphone.cpp

$(NAME) : $(SRCS)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS)

all : $(NAME)

clean :
	$(RM) $(NAME)

re :
	$(MAKE) clean
	$(MAKE) all
