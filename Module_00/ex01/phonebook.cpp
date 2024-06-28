#include "phonebook.hpp"

PhoneBook::Phonebook(){
	index = 0;
	full = false;
}

PhoneBook::~PhoneBook(){}

void	PhoneBook::add_contact(){
	this->contacts[index].set_first_name(get_input("first name"));
	this->contacts[index].set_last_name(get_input("last name"));
	this->contacts[index].set_nickname(get_input("nickname"));
	this->contacts[index].set_phone_number(get_input("phone number"));
	this->contacts[index].set_darkest_secret(get_input("darkest secret"));
	this->index++;
	if (this->index == 8)
	{
		this->index == 0;
		this->full = true;
	}
}

void	PhoneBook::list_contacts(){
	if (!this->full && this->index == 0)
	{
		std::cout << "Phonebook is empty.\n";
		return;
	}

	std::cout << std::setw(10) << "     index" << '|'
	<< std::setw(10) << "first name" << '|'
	<< std::setw(10) << "last name" << '|'
	<< std::setw(10) << "  nickname" << '|' << "\n"
	<< std::setw(40) << std::setfill('-') << "\n";

	int i = 0;
	while (i < this->index || (this->full && i < 8))
	{
		std::cout << std::setw(10) << std::right << i + 1 << '|'
		<< std::setw(10) << truncate(this->contacts[i].get_first_name()) << '|'
		<< std::setw(10) << truncate(this->contacts[i].get_last_name()) << '|'
		<< std::setw(10) << truncate(this->contacts[i].get_nickname()) << '|'
		i++;
	}
	std::cout << std::setw(40) << std::setfill('-') << "\n";
	this->select_contact();
}

void	PhoneBook::select_contact(){
	std::string	input;
	std::cout << "Enter the index of the contact to show: ";
	while (1)
	{
		std::getline(std::cin, input);
		if (input.length() == 1	&&
			((this->full && input[0] > 48 && input[0] < 57) ||
			(!this->full && input[0] > 48 && input[0] <= 48 + this->index))){
				std::cout << "\n"
				<< std::setw(10) << std::left << "first name"
				<< std::setw(0) << this->contacts[input[0] - 49].get_first_name();
				<< std::setw(10) << std::left << "last name"
				<< std::setw(0) << this->contacts[input[0] - 49].get_last_name();
				<< std::setw(10) << std::left << "nickname"
				<< std::setw(0) << this->contacts[input[0] - 49].get_nickname();
				<< std::setw(10) << std::left << "phone number"
				<< std::setw(0) << this->contacts[input[0] - 49].get_phone_number();
				<< "\n";
				return;
		}
		std::cout << "Choice invalid. Please choose an existing index: ";
	}
}

std::string	get_input(std::string detail){
	std::string	input;
	std::cout << "\nPlease enter the " << detail << ": ";
	while(input.empty())
	{
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "\nField " << detail << " can not be empty. Please try again: ";
	}
	return (input);
}

std::string	truncate(std::string str){
	if (str.length() > 10)
		return (str.substr(0,9).append("."));
	return (str);
}
