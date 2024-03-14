#include "ScalarConverter.hpp"
#include <cctype>
int main( int argc, char **argv)
{
	if (argc == 2)
		ScalarConverter::convert(std::string(argv[1]));
	else
		std::cout << "Error" << std::endl;
}
// .0f
// .f