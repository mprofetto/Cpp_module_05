# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 13:35:48 by mprofett          #+#    #+#              #
#    Updated: 2023/12/05 16:10:00 by mprofett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ./no_you_need_form_28B

SRC			= main.cpp Bureaucrat.cpp AForm.cpp ShrubberryCreationForm.cpp \
			RobotomyRequestForm.cpp PresidentialPardonForm.cpp

OBJ			= ${SRC:.cpp=.o}

CC			= c++

RM			= rm -rf

CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CPPFLAGS} ${OBJ} -o ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
