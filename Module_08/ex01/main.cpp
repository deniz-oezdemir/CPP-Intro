#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
	// test from subject
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;

	// test from subject but out of range
	{
		try {
			Span sp = Span(4);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	// test with 30000 random numbers
	{
		Span sp = Span(30000);
		std::vector<int> vec;
		for (int i = 0; i < 30000; i++)
			vec.push_back(i);
		sp.addRange(vec.begin(), vec.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;

	// test with 30000 random numbers
	{
		Span sp = Span(30000);
		std::vector<int> vec;
		for (int i = 0; i < 30000; i++)
			vec.push_back(rand());
		sp.addRange(vec.begin(), vec.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;

	// test with 30000 random numbers between 0 and 9
	{
		Span sp = Span(30000);
		std::vector<int> vec;
		for (int i = 0; i < 30000; i++)
			vec.push_back(rand() % 10);
		sp.addRange(vec.begin(), vec.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;

	// test with one random number between 0 and 9
	{
		try {
			Span sp = Span(1);
			std::vector<int> vec;
			for (int i = 0; i < 1; i++)
				vec.push_back(rand() % 10);
			sp.addRange(vec.begin(), vec.end());
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	return 0;
}
