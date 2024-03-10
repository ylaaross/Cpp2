#include "Serializer.hpp"

int main()
{
	uintptr_t ptru;
	Data *ptrd;
	Data d;
	d.i = 1;
	ptru = Serializer::serialize(&d);
	ptrd = Serializer::deserialize(ptru);
	std::cout << ptrd->i;
}