#include <iostream>
#include <cstdlib>
enum 
{
	ECHAR,
	EFLOAT
};
class ScalarConverter
{
	private:
		 ScalarConverter();
	public :
		static void convert(std::string str);
};