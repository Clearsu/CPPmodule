# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 18:17:02 by jincpark          #+#    #+#              #
#    Updated: 2023/04/04 22:17:04 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = claptrap

CC = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror

RM = rm -f

SRCS = main.cpp ClapTrap.cpp

OBJS = ${SRCS:.cpp=.o}

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean :
	$(MAKE) clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re
