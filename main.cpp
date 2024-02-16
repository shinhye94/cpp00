
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() 
{
	PhoneBook		phoneBook;
	std::string		cmd = "";

	while (true) 
	{
		std::cout << "Enter your command (ADD, SEARCH, EXIT) : ";
		if (!std::getline(std::cin, cmd))
			return (1);
		if (std::cin.eof())
			return (0);
		if (cmd == "ADD") 
		{
			if (phoneBook.addContact() == 1)
				return (1);
		}
		else if (cmd == "SEARCH") 
		{
			if (phoneBook.printContact() == 0 && phoneBook.printSelected() == 1)
				return (1);
		}
		else if (cmd == "EXIT") 
		{
			std::cout << "Exiting the program. Goodbye!\n";
			return (0);
		}
		else
			std::cout << cmd << "Command not found" << std::endl;;
	}
}
