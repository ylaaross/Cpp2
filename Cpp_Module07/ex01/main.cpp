#include  "iter.hpp"
#include <iostream>


int main()
{
    char t[10] = {'0','0','0','0','1','2' ,'5' ,'-' , '*'};
    ::iter(t, 10, print<char>);
   
    std::cout << std::endl;

    int s[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ::iter(s, 10, print<int>);
    std::cout << std::endl;
    return 0;
}






