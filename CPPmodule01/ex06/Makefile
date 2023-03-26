# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 17:14:19 by jincpark          #+#    #+#              #
#    Updated: 2023/03/24 20:40:12 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harl

CC = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror

RM = rm -f

SRCS = main.cpp Harl.cpp
OBJS = ${SRCS:.cpp=.o}

%.o : %.cpp
	$(CC) $(FLAGS) -I. -c $< -o $@

$(NAME) : $(SRCS)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) -I .

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
