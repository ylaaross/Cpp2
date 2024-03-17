#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * Base::generate(void)
{
	Base *d;
	static int i = 0;

	
	if(i == 3)
		i = 0;
	if(i == 0)
		d = new A();
	else if(i == 1)
		d = new B();
	else
		d = new C();
	i++;
	return d;
}

void Base::identify(Base* p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "another thing" << std::endl;
}

void Base::identify(Base& p)
{
	if(dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	else if(dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	else if(dynamic_cast<C*>(&p))
		std::cout << "C" << std::endl;
	else
		std::cout << "another thing" << std::endl;
}

Base::~Base()
{

}