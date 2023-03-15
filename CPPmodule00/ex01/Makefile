# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 18:17:02 by jincpark          #+#    #+#              #
#    Updated: 2023/03/15 15:18:44 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror
DFLAGS = -fsanitize=address

RM = rm -f

SRCS = main.cpp Contact.cpp PhoneBook.cpp

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
