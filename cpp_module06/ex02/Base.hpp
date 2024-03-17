#pragma once
class A;
class B;
class C;
// The rest of your header file contents...

#include <iostream>

class Base
{
	public:
		virtual ~Base();
		static Base * generate(void);
		static void identify(Base* p);
		static void identify(Base& p);
};