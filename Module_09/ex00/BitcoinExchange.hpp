#pragma once

#include <string>
#include <map>

class BitcoinExchange {
	private:
		std::map<std::string, double> dataMap_; //map stores data with string keys and double values

	public:
		BitcoinExchange(); //parses data.csv
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange();

		void	openInputAndExecute(std::string filename);
		void	checkDate(std::string date);
		double	checkAndGetValue(std::string value);
		void	printOutput(std::string date, double value);


		class OpenDataException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class OpenFileException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class InvalidValueException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class ValueOutOfRangeException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class NegativeValueException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class InvalidDateException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class EarlyDateException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};
