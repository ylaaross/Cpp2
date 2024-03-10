// #include <iostream>


// 	template <typename t>
// 	t change(t b[])
// 	{
// 		b[0] = b[0] + 1;
// 		return (b[0]);
// 	}
// 	template <typename t>
// 	void iter(t b[], int lenght, t(*change)(t b[]))
// 	{
// 		int i = 1;
	
// 		while (i < lenght)
// 		{
// 			b[i] =  change(b[i]);
// 			i++;
// 		}
// 	}


// iter.hpp
#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T b[], int length, T(*change)(T))
{
    for (int i = 0; i < length; ++i)
    {
        b[i] = change(b[i]);
    }
}

template <typename T>
T change(T value)
{
    return value + 1;
}

#endif
