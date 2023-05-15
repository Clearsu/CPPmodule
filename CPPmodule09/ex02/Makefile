# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 17:14:19 by jincpark          #+#    #+#              #
#    Updated: 2023/05/15 14:44:27 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CXX = c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

RM = rm -f

SRCS = main.cpp PmergeMe.cpp
OBJS = ${SRCS:.cpp=.o}

ifdef TEST
	CXXFLAGS += -DAVERAGE
endif

ifdef HUGE
	CXXFLAGS += -DHUGEVAL
endif

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

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

.PHONY : all clean fclean re test huge
