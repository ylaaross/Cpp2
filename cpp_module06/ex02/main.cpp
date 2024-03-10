#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
int main()
{
	C c = C();
	Base &Bts = c;
	Base::identify(Bts);
}