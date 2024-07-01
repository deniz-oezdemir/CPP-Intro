#include "Account.hpp"
#include <iomanip>
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
	_displayTimestamp();
	std::cout << "index:" << _nbAccounts << ';'
	<< "amount:" << initial_deposit << ';'
	<< "created" << "\n";
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
}

Account::~Account(){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
	<< "amount:" << this->_amount << ';' << "closed" << "\n";
}

int	Account::getNbAccounts(){
	return (_nbAccounts);
}

int	Account::getTotalAmount(){
	return (_totalAmount);
}

int	Account::getNbDeposits(){
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(){
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(){
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ';'
	<< "total:" << _totalAmount << ';'
	<< "deposits:" << _totalNbDeposits << ';'
	<< "withdrawals:" << _totalNbWithdrawals << "\n";
}

void	Account::makeDeposit(int deposit){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
	<< "p_amount:" << this->_amount << ';'
	<< "deposit:" << deposit << ';';
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "amount:" << this->_amount << ';'
	<< "nb_deposits:" << this->_nbDeposits << "\n";
}

bool	Account::makeWithdrawal(int withdrawal){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
	<< "p_amount:" << this->_amount << ';';
	if (withdrawal <= this->_amount){
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << "withdrawal:" << withdrawal << ';'
		<< "amount:" << this->_amount << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals << "\n";
		return true;
	} else {
		std::cout << "withdrawal:refused" << "\n";
		return false;
	}
}

void	Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
	<< "amount:" << _amount << ';'
	<< "deposits:" << _nbDeposits << ';'
	<< "withdrawals:" << _nbWithdrawals << "\n";
}

void	Account::_displayTimestamp(){
	std::time_t	current_time = std::time(NULL);
	std::tm*	local_time = std::localtime(&current_time);

	char buffer[25];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", local_time);
	std::cout << buffer << ' ';
}
