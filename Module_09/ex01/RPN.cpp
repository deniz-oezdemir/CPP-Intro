#include "RPN.hpp"
#include <cmath>
#include <sstream>
#include <cctype>

RPN::RPN(const std::string& RPNExpression) {
	try {
		evaluateRPNExpression(RPNExpression);
		std::cout << this->numberStack_.top() << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return ;
}

RPN::RPN(const RPN &src) {
	*this = src;
	return ;
}

RPN &RPN::operator=(const RPN &src) {
	if (this != &src) {
		this->numberStack_ = src.numberStack_;
	}
	return (*this);
}

RPN::~RPN() {
}

void RPN::evaluateRPNExpression(const std::string& RPNExpression) {
	char current;
	double a;
	double b;
	size_t size = RPNExpression.size();

	for (size_t i = 0; i < size; ++i) {
		current = RPNExpression[i];
		if (isdigit(current))
			this->numberStack_.push(current - '0');
		else if (current == '+' || current == '-' || current == '*' || current == '/') {
			if (this->numberStack_.size() < 2)
				throw RPN::InvalidRPNExpressionException();
			b = this->numberStack_.top();
			this->numberStack_.pop();
			a = this->numberStack_.top();
			this->numberStack_.pop();
			if (current == '+') {
				this->numberStack_.push(a + b);
			} else if (current == '-') {
				this->numberStack_.push(a - b);
			} else if (current == '*') {
				this->numberStack_.push(a * b);
			} else if (current == '/') {
				if (b == 0) {
					throw RPN::InvalidRPNExpressionException();
				}
				this->numberStack_.push(a / b);
			}
		}
		else if (current == ' ')
			continue;
		else
			throw RPN::InvalidRPNExpressionException();
	}
	if (this->numberStack_.size() != 1) { //in case of too many operands or too few operators
		throw RPN::InvalidRPNExpressionException();
	}
}

const char *RPN::InvalidRPNExpressionException::what() const throw() {
	return "Error: Invalid RPN RPNExpression";
}
