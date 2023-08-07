SRCS		= main.cpp\
				Bureaucrat.cpp\
				AForm.cpp\
				PresidentialPardonForm.cpp\
				RobotomyRequestForm.cpp\
				ShrubberyCreationForm.cpp\
				Intern.cpp
INCS		= Bureaucrat.hpp\
				AForm.hpp\
				PresidentialPardonForm.hpp\
				RobotomyRequestForm.hpp\
				ShrubberyCreationForm.hpp\
				Intern.hpp
OBJS		= ${SRCS:.cpp=.o}
NAME		= test
CXX			= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98 -fsanitize=address

$(NAME):	${OBJS} ${INCS}
			${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all