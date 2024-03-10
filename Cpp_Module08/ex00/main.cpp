#include "easyfind.hpp"

int main()
{
	try
	{
		std::vector<int> myVector;
		myVector.push_back(1);
		myVector.push_back(2);
		myVector.push_back(3);
		std::cout << easyfind(myVector, 5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}