#include "BitcoinExchange.hpp"
int main(int argc, char **argv)
{
	if(argc == 2)
	{
		read_database();
	}
	else
		std::cout << "error" << std::endl;
}