	#include <iostream>
	#include <exception>
	#include <vector>
	class GradeTooLowException:public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return("there is no value\n");
			}
	};
	template<typename T>
	T easyfind(std::vector<T>& vec, int oc)
	{
		int i = 0;

		while(i < vec.size())
		{
			if(vec[i] == oc)
				return oc;
			i++;
		}
		throw GradeTooLowException();
	}







// 	#include <iostream>
// #include <vector>
// #include <exception>
// #include <string>

// class MyException : public std::exception {
// private:
//     std::string message;

// public:
//     MyException(const std::string& msg) : message(msg) {}

//     // Correct the noexcept specification to match the base class
//     const char* what() const noexcept override {
//         return message.c_str();
//     }
// };

// int easyfind(std::vector<int>& vec, int oc) {
//     for(int i = 0; i < vec.size(); ++i) {
//         if(vec[i] == oc)
//             return i; // Return the index, not the value
//     }
//     // If the function reaches this point, the element was not found
//     throw MyException("Value not found in the vector");
// }
