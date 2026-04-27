#ifndef BASE_HPP
# define BASE_HPP

class Base {
	public:
		virtual ~Base();
};

Base	*generate(void);
void	identify(Base *ptr);
void	identify(Base &ref);

#endif
