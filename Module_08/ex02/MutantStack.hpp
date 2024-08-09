#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(){};
		MutantStack(MutantStack const &src):std::stack<T>(src){};
		~MutantStack(){};

		MutantStack &operator=(MutantStack const &assign){
			if (this != &assign)
				std::stack<T>::operator=(assign);
			return (*this);
		};

		// Define a typedef for the iterator type of the underlying container of the stack
		typedef typename std::stack<T>::container_type::iterator iterator;

		// Returns an iterator pointing to the beginning of the underlying container
		iterator begin() {
			return (this->c.begin());
		};

		// Returns an iterator pointing to the end of the underlying container
		iterator end() {
			return (this->c.end());
		};
};
