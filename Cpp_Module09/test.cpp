#include <iostream>
int main()
{
	int i=2;
	int x = 0;

	try
	{
		
		if(x == 0)
			throw std::exception();
		else
			i = i / x;
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << "ssssssss" << std::endl;
	return (0);
}