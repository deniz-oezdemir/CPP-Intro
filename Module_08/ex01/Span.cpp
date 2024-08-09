#include "Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span() : N_(0) {}

Span::Span(unsigned int N) : N_(N) {}

Span::Span(const Span &src) : N_(src.N_), vec_(src.vec_) {}

Span::~Span() {}


Span &Span::operator=(Span const &assign) {
	if (this != &assign) {
		this->N_ = assign.N_;
		this->vec_ = assign.vec_;
	}
	return *this;
}


void Span::addNumber(int n) {
	if (this->vec_.size() >= this->N_)
		throw Span::ExceptionFull();
	this->vec_.push_back(n);
}

unsigned int Span::shortestSpan() {
	if (this->vec_.size() <= 1)
		throw Span::ExceptionNoSpan();

	std::vector<int> tmp = this->vec_;
	std::sort(tmp.begin(), tmp.end());

	unsigned int shortest = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); i++) {
		unsigned int distance = tmp[i] - tmp[i - 1];
		if (distance < shortest)
			shortest = distance;
	}
	return shortest;
}

unsigned int Span::longestSpan() {
	if (this->vec_.size() <= 1)
		throw Span::ExceptionNoSpan();

	int max = *std::max_element(vec_.begin(), vec_.end());
	int min = *std::min_element(vec_.begin(), vec_.end());
	return (max - min);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (this->vec_.size() + std::distance(begin, end) > this->N_)
		throw Span::ExceptionFull();
	this->vec_.insert(this->vec_.end(), begin, end);
}

const char *Span::ExceptionFull::what() const throw() {
	return ("Span too full");
}

const char *Span::ExceptionNoSpan::what() const throw() {
	return ("Span contains one element or is empty");
}

