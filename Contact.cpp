
#include "Contact.hpp"

std::string Contact::getFirstName() 
{
    return firstName;
}

void printColumn(const std::string s) 
{
	int len;
	int i;
	len = s.length();
	if (len > 10) {
		for (i = 0; i < 9; i++)
			std::cout << s[i];
		std::cout << ".";
		return ;
	}
	for (i = 0; i < 10 - len; i++)
		std::cout << " ";
	std::cout << s;
}

void Contact::printSavedList(int idx) 
{
	std::cout << "|";
	std::cout << "         ";
	std::cout << idx;
	std::cout << "|";
	printColumn(firstName);
	std::cout << "|";
	printColumn(lastName);
	std::cout << "|";
	printColumn(nickName);
	std::cout << "|";
	std::cout << std::endl;
}

void Contact::printDetail(void) 
{
	if (!firstName.compare("")) 
	{
		std::cout << "No contact available for the index\n";
		return ;
	}
    const char* fieldNames[] = {"First name", "Last name", "Nick name", "Phone number", "Darkest secret"};
    std::string* fields[] = {&firstName, &lastName, &nickName, &phoneNum, &darkestSecret};

    for (int i = 0; i < 5; i++)
    {
        std::cout << fieldNames[i] << " : ";
        std::cout << *fields[i]<< std::endl;
    }
}

bool is_number(const std::string s) {
	int	i;

	for (i = 0 ; s[i]; i++) {
		if (!isdigit(s[i]))
			return (false);
	}
	return (true);
}

int Contact::inputContact() 
{
    const char* fieldNames[] = {"First name", "Last name", "Nick name", "Phone number", "Darkest secret"};
    std::string* fields[] = {&firstName, &lastName, &nickName, &phoneNum, &darkestSecret};

    for (int i = 0; i < 5; ++i) 
	{
        std::cout << "ENTER " << fieldNames[i] << "?: ";
        while (true) 
		{
            if (!std::getline(std::cin, *fields[i]))
                return 1;

            if (!fields[i]->empty()) 
			{
                if (i == 3 && !is_number(*fields[i])) 
				{
                    std::cout << "Enter only numbers with no blanks: ";
                    continue;
                }
                break;
            } else 
                std::cout << "The field can't be empty: ";
        }
    }	
    return (0);
}
