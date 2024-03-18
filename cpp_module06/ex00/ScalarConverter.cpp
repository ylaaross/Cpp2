#include <iostream>
#include "ScalarConverter.hpp"
#include <iomanip>
#include <limits>
ScalarConverter::ScalarConverter()
{

}

char sign(double nbr)
{
	if(nbr > 0)
		return '+';
	return '-';
}

int after_dot(char* str, std::string stro)
{
	int i = 1;
	std::string s;
	if(stro == "NAN" || stro == "nan")
	
		return (0);
	if (!str || strlen(str) == 0)
		return (1);
	s = str;
	if(s.length() > 1)
	
		return(0);
	if (s[0] != 'f' && s[0] != 'F')
		return (0);
	return (1);
}


void	print_char(int after_dot, char ch)
{
	if(after_dot)
	{
		if (std::isprint(ch))
			std::cout << "char: " << ch << std::endl;
		else
			std::cout << "char: " << "Non displayable" << std::endl;
	}
	else
		std::cout << "char: " << "impossible" << std::endl;
}
void print_int(int after_dot, int nbr, double doublen)
{
	std::cout << std::numeric_limits<int>::max() << std::endl;
	if(after_dot)
	{
		if(doublen <= std::numeric_limits<int>::max() && doublen >= std::numeric_limits<int>::min())
			std::cout << "int: " << nbr << std::endl;
		else
			std::cout << "int: " << sign(doublen) << "inf" << std::endl;
	}
	else
		std::cout << "int: " << "impossible" << std::endl;
}

void print_float(int after_dot, float floatn)
{
	if(after_dot)
		std::cout << "float: " << std::fixed << std::setprecision(2) << floatn << "f" << std::endl;
	else
		std::cout << "float: "<< "nanf" << std::endl;
}
void print_double(int after_dot, double doublen)
{
	if(after_dot)
		std::cout << "double: " << doublen << std::endl;
	else
		std::cout << "double: "<< "nan" << std::endl;
}
void	ScalarConverter::convert(std::string str)
{
	char *strnc = 0;
	const char *strc = str.c_str();
	char* rest = 0;
	double doublen;
	float floatn;
	int nbr;
	char ch;
	int after;

	if(str.length() == 1 && !std::isdigit(str[0]))
		doublen = strc[0];
	else
		doublen = std::strtod(strc ,&rest);
	after = after_dot(rest, str);
	nbr = static_cast <int> (doublen);
	ch = static_cast <char> (nbr);
	floatn = static_cast <float> (doublen);
	print_char(after, ch);
	print_int(after, nbr , doublen);
	print_float(after, floatn);
	print_double(after, doublen);
}
