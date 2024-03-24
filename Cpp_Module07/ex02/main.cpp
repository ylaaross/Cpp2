#include "Array.hpp"
int main()
{
	try
	{
		int i=0;
		Array<int> ar(3);
		ar[0] = 1;
		ar[1] = 2;
		ar[2] = 3;
		Array<std::string>arr(3);
		arr[0] = "yassir";
		arr[1] = "laarossi";
		arr[2] = "dev";
		while(i < arr.size())
		{
			std::cout << ar[i] << std::endl;
			i++;
		}
        i = 0;
        while(i < arr.size())
		{
			std::cout << arr[i] << std::endl;
			i++;
		}
		std::cout << arr[6] << std::endl;
	}
	catch(std::out_of_range e)
	{
		std::cout << e.what();
    }
    return(0);
}
