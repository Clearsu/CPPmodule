# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 17:14:19 by jincpark          #+#    #+#              #
#    Updated: 2023/05/06 15:31:19 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = span

CXX = c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

RM = rm -f

SRCS = main.cpp Span.cpp
OBJS = ${SRCS:.cpp=.o}

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

.PHONY : all clean fclean re
