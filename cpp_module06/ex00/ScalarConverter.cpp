#include <iostream>
#include <cstdlib>
#include "ScalarConverter.hpp"
#include <string>
#include <iomanip>

ScalarConverter::ScalarConverter()
{

}

char sign(double nbr)
{
	if(nbr > 0)
		return '+';
	return '-';
}

void ScalarConverter::convert(std::string str)
{
	char *strnc = 0;
	const char *strc = str.c_str();
	char* rest;
	double doublen;
	float floatn;
	int nbr;
	char ch;

	if(str.length() == 1 && !std::isdigit(str[0]))
		doublen = strc[0];
	else
		doublen = std::strtod(strc ,&rest);
	nbr = static_cast <int> (doublen);
	ch = static_cast <char> (nbr);
	floatn = static_cast <float> (doublen);
	if(std::isprint(ch))
		std::cout << "char: " << ch << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	if(nbr == doublen)
		std::cout << "int: " << nbr << std::endl;
	else
		std::cout << "int: " << sign(doublen) <<"inf" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << floatn << std::endl;
	std::cout << "double: " << doublen << std::endl;
}
