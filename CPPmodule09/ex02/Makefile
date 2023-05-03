# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 17:14:19 by jincpark          #+#    #+#              #
#    Updated: 2023/05/03 01:48:33 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CC = c++

FLAGS = -std=c++98 -Wall -Wextra -Werror -fsanitize=address -g3

RM = rm -f

SRCS = main.cpp PmergeMe.cpp
OBJS = ${SRCS:.cpp=.o}

ifdef TEST
	FLAGS += -DAVERAGE
endif

ifdef HUGE
	FLAGS += -DHUGEVAL
endif

%.o : %.cpp
	$(CC) $(FLAGS) -I. -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) -I. $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean :
	$(MAKE) clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

test :
	$(MAKE) TEST=1 all

huge :
	$(MAKE) HUGE=1 all

.PHONY : all clean fclean re
