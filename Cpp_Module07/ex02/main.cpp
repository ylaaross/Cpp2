#include "Array.hpp"
int main()
{
	int i=0;

	Array<int> ar(3);
	ar[0] = 1;
	ar[1] = 2;
	ar[2] = 3;
	Array<std::string>arr(3);
	arr[0] = "yassir";
	arr[1] = "laarossi";
	arr[2] = "lking";
	while(i < arr.size())
	{
		std::cout << arr[i] << std::endl;
		i++;
	}
}