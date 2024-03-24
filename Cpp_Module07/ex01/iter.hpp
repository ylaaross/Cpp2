#include <iostream>
#pragma once

template <typename T>
void iter(T b[], int length, void(*print)(T))
{
    for (int i = 0; i < length; ++i)
        print(b[i]);
}

template <typename T>
void print(T value)
{
    std::cout << value << std::endl;
}
