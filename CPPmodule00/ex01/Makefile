# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 18:17:02 by jincpark          #+#    #+#              #
#    Updated: 2023/03/22 16:12:00 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror
DFLAGS = -fsanitize=address

RM = rm -f

SRCS = main.cpp Contact.cpp PhoneBook.cpp

OBJS = ${SRCS:.cpp=.o}

ifdef IF_DEBUG
	$(FLAGS) += $(DFLAGS)
endif

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@ -I.

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -I.

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean :
	$(MAKE) clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

debug :
	$(MAKE) IF_DEBUG=1

.PHONY : all clean fclean re debug
