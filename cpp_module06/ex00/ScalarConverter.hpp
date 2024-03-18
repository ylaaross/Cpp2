#include <iostream>
#include <string>
class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &scalar);
		ScalarConverter &operator =(const ScalarConverter &scalar);
		~ScalarConverter();
	public :
		static void convert(std::string str);
};