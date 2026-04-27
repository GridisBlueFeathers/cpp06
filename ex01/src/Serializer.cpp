#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data *raw) {
	return (reinterpret_cast<uintptr_t>(raw));
}

Data		*Serializer::deserialize(uintptr_t ptr) {
	return (reinterpret_cast<Data *>(ptr));
}
