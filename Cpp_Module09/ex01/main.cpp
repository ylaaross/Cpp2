#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{	
		RPN n;
		n.split(argv[1]);
		n.showresult();
	}	
	else
		std::cout << "Error" << std::endl;
}


