#include "RPN.hpp"

void	RPN::showresult()
{
    if(stack.size() == 1)
        std::cout << stack.top();
    else
    {
        std::cout << "Error" << std::endl;
        exit(1);
    }
}

int RPN::convert(std::string str)
{
    int i;
    char *reminder = NULL;
    const char *charPtr = str.c_str();
    i = strtod(charPtr, &reminder);
    std::cout << std::endl;
    if (strlen(reminder) > 0)
    {
        std::cout << "sss";
        std::cout << reminder;
        std::cout << "Error" << std::endl;
        exit(1);
    }
    return (i);
}

int  RPN::calculate(int nbr1,int nbr2 , std::string &s)
{
    if(s == "+")
        return (nbr1 + nbr2);
    else if(s == "-")
        return (nbr1 - nbr2);
    else if(s == "/")
        return (nbr1 / nbr2);
    else
        return (nbr1 * nbr2);   
}

void RPN::push_convert(std::string &s)
{
    int i = 0;
    int arr[2];
    
    if (s == "+" || s == "-" || s == "*" || s == "/")
    {
      
        while (i < 2 && !stack.empty())
        {
            arr[i] = stack.top();
            stack.pop();
            i++;
        }
        if (i < 2)
        {

            std::cout << "Error" << std::endl;
            exit(1);
        }
        else
            stack.push(calculate(arr[1], arr[0], s));
    }
    else
        stack.push(convert(s));
}
void RPN::split(std::string s)
{
    std::string token;
    size_t pos = 0;
    size_t start = 0;
    while ((pos = s.find(32, start)) != std::string::npos || (pos = s.find(9, start)) != std::string::npos || (pos = s.find(11, start)) != std::string::npos)
    {
        token = s.substr(start, pos - start);
        if (!token.empty())
            push_convert(token);
        start = pos + 1;
    }
    token = s.substr(start);
    if (!token.empty())
        push_convert(token);
}

