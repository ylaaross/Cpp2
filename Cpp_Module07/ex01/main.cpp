// #include  "iter.hpp"

// int main()
// {
// 	int t[10];
// 	::iter(t,10,change(t));
// 	return (0);
// }

// main.cpp
#include <iostream>
#include "iter.hpp"

int main()
{
    char t[10] = {'0','0','0','0'}; // Initialize the array to avoid undefined behavior
    ::iter(t, 10, change<char>);
    for (int i = 0; i < 10; ++i)
    {
        std::cout << t[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
