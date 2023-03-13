# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 18:17:02 by jincpark          #+#    #+#              #
#    Updated: 2023/03/11 15:37:36 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = c++

FLAGS = -std=c++98 
#-Wall -Wextra -Werror

RM = rm -f

SRCS = phonebook.cpp

$(NAME) : $(SRCS)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) -I .

all : $(NAME)

clean :
	$(RM) $(NAME)

re :
	$(MAKE) clean
	$(MAKE) all
