#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast <uintptr_t>(ptr));
}
Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast <Data*>(raw));
}

Serializer::Serializer()
{

}

Serializer::~Serializer()
{
	
}

Serializer & Serializer::operator=(Serializer const & Serialize)
{
	(void) Serialize;
	return *this;
}

Serializer::Serializer(Serializer const & Serialize)
{
	*this = Serialize;
}