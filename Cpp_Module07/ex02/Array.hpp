#include<iostream>
#pragma once

template <typename t>
class Array 
{
	private:
		t		*array;
		int		length;
	public:
		Array()
		{
			array = NULL;
			length = 0;
		}
		Array(unsigned int n)
		{

			length = n;
			array = new t[n];
		}
		
		Array(const Array & cp)
		{
			*this = cp; 
		}

		Array & operator=(const Array &cp) 
		{
			if (this != &cp)
			{
				int i = 0;
				if(cp.length >= 1)
				{
					array = new t[cp.length];
					while (i < cp.length)
					{
						array[i] = cp.array[i];
						i++;
					}
					length = cp.length;
				}
				else if(cp.length == 0)
				{	
					length = 0;
					array = 0;
				}
			}
			return *this;
		}

		~Array() 
		{
			if (array)
        		delete[] array;
			array = NULL;
    	}

		int size() const
		{
			return length;
		}

		t &operator[] (int index)
		{
			if (index < 0 || index >= length)
				throw std::out_of_range("Your out of range!!");
			return array[index];
		}
};
