#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

BitcoinExchange::BitcoinExchange() {
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw OpenDataException();

	std::string line;
	std::getline(file, line); //ignore column titles

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date;
		double exchangeRate;

		std::getline(ss, date, ','); //extract date from ss (before comma)
		ss >> exchangeRate; //extract exchangeRate from ss (remaining part) // >> interprets type double correctly

		this->dataMap_[date] = exchangeRate; //store date and exchangeRate in map data
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
	if (this != &src)
		this->dataMap_ = src.dataMap_;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}


void BitcoinExchange::openInputAndExecute(std::string filename) {
		std::ifstream file(filename.c_str());
		if (!file.is_open())
			throw OpenFileException();

		std::string line;
		std::getline(file, line); //ignore column titles

		while (std::getline(file, line)) {
			std::stringstream ss(line);
			std::string date;
			std::string value;

			std::getline(ss, date, '|');
			date.erase(remove_if(date.begin(), date.end(), isspace), date.end()); //remove whitespace
			std::getline(ss, value, '\n');
			value.erase(remove_if(value.begin(), value.end(), isspace), value.end());
			try {
				checkDate(date);
				printOutput(date, checkAndGetValue(value));
			} catch(const std::exception& e) {
				std::cerr << e.what() << '\n';
			}
		}
		return ;
}

void BitcoinExchange::checkDate(std::string date) {
	if(date.size() != 10 || date[4] != '-' || date[7] != '-')
		throw InvalidDateException();

	int year, month, day;
	std::istringstream(date.substr(0, 4)) >> year; //read data from string as if it were a stringstream
	std::istringstream(date.substr(5, 2)) >> month;
	std::istringstream(date.substr(8, 2)) >> day;

	if(year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
		throw InvalidDateException();

	if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		throw InvalidDateException();

	if(month == 2) {
		bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if(day > 29 && isLeapYear)
			throw InvalidDateException();
		if(day > 28 && !isLeapYear)
			throw InvalidDateException();
	}
}

double BitcoinExchange::checkAndGetValue(std::string value) {
	if (value.find_first_not_of("0123456789.-") != std::string::npos)
		throw InvalidValueException();

	bool isEmpty = value.empty();
	bool startsWithDot = !value.empty() && value[0] == '.';
	bool endsWithDot = !value.empty() && value[value.size() - 1] == '.';
	bool hasLeadingZero = value.size() > 1 && value[0] == '0' && value[1] != '.';
	if (isEmpty || startsWithDot || endsWithDot || hasLeadingZero) {
		throw InvalidValueException();
	}

	double result;
	try {
		std::istringstream(value) >> result;
	} catch (const std::invalid_argument& e) {
		throw InvalidValueException();
	} catch (const std::exception& e) {
		throw InvalidValueException();
	}

	if (result > 1000.0)
		throw ValueOutOfRangeException();
	if (result < 0.0)
		throw NegativeValueException();

	return result;
}

void BitcoinExchange::printOutput(std::string date, double value) {
	double exchangeRate;
	if (this->dataMap_.count(date) > 0){ //check if date exists in dataMap_
		exchangeRate = this->dataMap_[date];
		std::cout << date << " => " << value << " = " << exchangeRate * value << std::endl;
	} else {
		std::map<std::string, double>::iterator it = dataMap_.lower_bound(date); //find first element not less than given date
		if (it == this->dataMap_.begin())
			throw EarlyDateException();
		else {
			--it; //iterate to closest earlier date
			exchangeRate = it->second;
			std::cout << date << " => " << value << " = " << exchangeRate * value << std::endl;
		}
	}
}


const char *BitcoinExchange::OpenDataException::what() const throw() {
	return ("Error: could not open data.");
}

const char *BitcoinExchange::OpenFileException::what() const throw() {
	return ("Error: could not open file.");
}

const char *BitcoinExchange::InvalidValueException::what() const throw() {
	return ("Error: invalid value.");
}

const char *BitcoinExchange::ValueOutOfRangeException::what() const throw() {
	return ("Error: too large a number.");
}

const char *BitcoinExchange::NegativeValueException::what() const throw() {
	return ("Error: not a positive number.");
}

const char *BitcoinExchange::InvalidDateException::what() const throw() {
	return ("Error: invalid date.");
}

const char *BitcoinExchange::EarlyDateException::what() const throw() {
	return ("Error: too early date.");
}
