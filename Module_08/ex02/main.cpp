#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	// subject's test: compare with below implementation with lists
	{
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << "MutantStack: " << mstack.size() << " | Stack: " << s.size() << std::endl;
		while (!mstack.empty())
		{
			mstack.pop();
		}
		std::cout << "MutantStack: " << mstack.size() << " | Stack: " << s.size() << std::endl;
	}

	std::cout << std::endl;

	// subject's test: implementation with lists
	{
	std::list<int>	mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;

	mstack.pop_back();

	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
	std::cout << "MutantStack: " << mstack.size() << " | Stack: " << s.size() << std::endl;
	while (!mstack.empty())
	{
		mstack.pop_back();
	}
	std::cout << "MutantStack: " << mstack.size() << " | Stack: " << s.size() << std::endl;
	}

	std::cout << std::endl;

	// further tests: strings
	{
		MutantStack<std::string> mstack;

		mstack.push("John");
		mstack.push("Alice");

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push("Bob");
		mstack.push("Mary");
		mstack.push("Alex");

		MutantStack<std::string>::iterator it = mstack.begin();
		MutantStack<std::string>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<std::string> s(mstack);
		std::cout << "MutantStack: " << mstack.size() << " | Stack: " << s.size() << std::endl;
		while (!mstack.empty())
		{
			mstack.pop();
		}
		std::cout << "MutantStack: " << mstack.size() << " | Stack: " << s.size() << std::endl;
	}

	return 0;
}
