cc		= c++

SRC		=  Bureaucrat.cpp AForm.cpp main.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

FLAGS	= -Wall -Wextra -Werror -std=c++98

fileo	= $(SRC:.cpp=.o)

Name	= Bureaucrat

all		: $(Name)

$(Name) : $(fileo)
		$(cc) $(FLAGS) $(fileo) -o $@

%.o		:  %.cpp Bureaucrat.hpp
		$(cc) $(FLAGS) $(file) -c $<

clean	:
		rm -rf $(fileo)

fclean	: clean
		rm -rf $(Name)

re		: fclean all
	
.Phony : clean fclean re
	