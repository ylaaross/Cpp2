#include <iostream>
#include <vector>

class Span
{
	private :
		int nbr;
		std::vector<int> number;
 	public:
	Span(unsigned int N)
 	{
		this->nbr = N;
 	}

	Span()
	{
		this->nbr = 0;
	}

	void addNumber(int N)
	{
		if(nbr > 0)
			number.push_back(N);
		else 
			std::cout << "You can not add a number" << std::endl;
		nbr--;
	}

	template <typename Iterator>
	void store(Iterator begin, Iterator end)
	{
		int count = 0;	
		for (Iterator it = begin; it != end && count < nbr; ++it,count++)
    	{
			number.push_back(*it);
		}	
		
	}
	void print()
	{
		int i = 0;

		while(i < number.size())
		{
			std::cout << number[i] << std::endl;
			i++;
		}

	}

	int diff(int nbr1, int nbr2)
	{
		if(nbr1 > nbr2)
			return (nbr1 - nbr2);
		else
			return (nbr2 - nbr1);
	}

	void shortestSpan()
	{
		int shortd;
		int longd;
		int inter;

		bool s = 0;
		int i = 0;
		int j = 0;
		while(i < number.size() - 1)
		{
			j = i + 1;
			while(j < number.size())
			{
				if(!s)
				{
					
					shortd = diff(number[j], number[i]);
					
					s = 1;
				}
				else
				{
					inter = diff(number[j], number[i]);
					if (inter < shortd)
						shortd = inter;
					if (longd < inter)
						longd = inter;
				}
				std::cout << number[j] << "  " << number[i] << std::endl; 
				j++;
			}
			i++;
		}
		std::cout << shortd << std::endl;
		std::cout << longd << std::endl;
		return;
	}
};