#pragma once

#include <vector>

class Span {
	private:
		unsigned int				N_;
		std::vector<int>			vec_;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		~Span();
		Span &operator=(Span const &assign);

		void	addNumber(int n);
		unsigned int		shortestSpan();
		unsigned int		longestSpan();
		void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		class ExceptionFull : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class ExceptionNoSpan : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};
