#pragma once

#include <string>
#include <stack>
#include <iostream>

class RPN {
	private:
		std::stack<int> numberStack_;

	public:
		RPN(const std::string& RPNExpression);
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
		~RPN();

		void evaluateRPNExpression(const std::string& RPNExpression);

		class InvalidRPNExpressionException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};
