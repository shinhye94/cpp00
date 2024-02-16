
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>
# include <iostream>
# include "Contact.hpp"

class PhoneBook 
{
	private:
		Contact contacts[8];
		int		idx;
	public:
		PhoneBook(void);
		int 			addContact(void);
		int				printContact(void);
		int 			printSelected(void); 
		bool 			checkEmpty(int i);
};

#endif
