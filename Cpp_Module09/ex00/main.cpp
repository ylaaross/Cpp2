#include "BitcoinExchange.hpp"
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		BitcoinExchnage e;
		e.read_database();
		e.read("test.txt");
	}
	else
		std::cout << "error" << std::endl;
}

