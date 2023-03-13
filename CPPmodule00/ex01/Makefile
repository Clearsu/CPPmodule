# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 18:17:02 by jincpark          #+#    #+#              #
#    Updated: 2023/03/13 21:42:33 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = c++

FLAGS = -std=c++98 
#-Wall -Wextra -Werror

RM = rm -f

SRCS = main.cpp Contact.cpp PhoneBook.cpp

$(NAME) : $(SRCS)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) -I .

all : $(NAME)

clean :
	$(RM) $(NAME)

re :
	$(MAKE) clean
	$(MAKE) all
