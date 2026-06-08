#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>

# include "Data.hpp"

class Serializer {
	private:
		Serializer();

	public:
		static uintptr_t	serialize(Data *raw);
		static Data			*deserialize(uintptr_t ptr);
};

#endif
