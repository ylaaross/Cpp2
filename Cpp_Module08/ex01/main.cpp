#include "Span.hpp"

int main()
{
	Span s(1000);

	// s.addNumber(-1);
	// s.addNumber(-11);
	// s.addNumber(0);
	// s.addNumber(1);
	// s.addNumber(6);
	// s.shortestSpan();
	  std::vector<int> numbers;


    for (int i = 0; i < 1000; ++i) {
        numbers.push_back(i);
    }

	s.store(numbers.begin(), numbers.end());
	s.print();
}