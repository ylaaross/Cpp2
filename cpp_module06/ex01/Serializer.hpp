#include <iostream>

struct Data
{
	int i;
};
class Serializer 
{
		private :
			Serializer();
			~Serializer();
			Serializer(Serializer const & Serialize);
			Serializer & operator=(Serializer const & Serialize);

		
	public:
		
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};