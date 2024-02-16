
#include "PhoneBook.hpp"

void printColumn(const std::string s);
bool is_number(const std::string s);

bool	PhoneBook::checkEmpty(int i) 
{
    return contacts[i].getFirstName().empty();
}

PhoneBook::PhoneBook(void) 
{
	idx = 0;
}

int PhoneBook::addContact(void) 
{
	if (contacts[idx].inputContact()) 
	{
		std::cerr<< "\nSomething went wrong!\n";
		return (1);
	}
	std::cout << "Successfully added!\n";
	if (idx < 7)
		idx++;
	return (0);
}

int PhoneBook::printContact() 
{
	int i;
	
	if (checkEmpty(0))
	{
		std::cout << "Oops! Phonebook is still empty.\n";
		return (1);
	}
	std::cout << std::endl;
	std::cout << "|";
	printColumn("index");
	std::cout << "|";
	printColumn("first name");
	std::cout << "|";
	printColumn("last name");
	std::cout << "|";
	printColumn("nick name");
	std::cout << "|";
	std::cout << std::endl;
	for (i = 0; i < 8; i++)
		contacts[i].printSavedList(i + 1);
	return (0);
}

int PhoneBook::printSelected(void) 
{
	std::string	userInput;

	while (true) {
		std::cout << "Enter a number between 1 and 8 :";
		if (!std::getline(std::cin, userInput))
		{
			std::cerr << "\nSomething went wrong!\n";
			return (1);
		}
		if (is_number(userInput) && userInput.length() == 1)
		{
			int i = userInput[0] - '1';
			if (i >= 0 && i < 8 && (!checkEmpty(i)))
			{
				contacts[i].printDetail();
				return (0);
			}
		}
	}
}

/*
int PhoneBook::printSelected(void) {
	std::string	userInput;

	while (true) {
		std::cout << "Enter a number between 1 and 8 :";
		if (!std::cin >> userInput)
		{
			std::cerr << "\nSomething went wrong!\n";
			return (1);
		}
		if (!(!is_number(userInput) || userInput.length() > 1 || \
			userInput[0] < '1' || userInput[0] > '8')) 
			{
				contacts[userInput[0] - '1'].printDetail();
				return (0);
		}
	}
}
*/