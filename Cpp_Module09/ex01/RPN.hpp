#include <iostream>
#include <string>
#include <stack>

class RPN
{
	private:
	    std::stack<int> stack;
	public:
		void	showresult();
		void	store(std::string str);
		void	split(std::string str);
		void	addition();
		bool	isValid(std::string str);
		void	push_convert(std::string& s);
		int		convert(std::string str);
		int		calculate(int nbr1,int nbr2 , std::string &s);
};