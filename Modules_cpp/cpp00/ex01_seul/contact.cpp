#include "contact.hpp"
#include "utils.hpp"

Contact::Contact(void) {
	_fname = "NONE";
	_lname = "NONE";
	_nname = "NONE";
	_phone_num = "NONE";
	_secret = "NONE";
}

Contact::~Contact(void) {
	return;
}

std::string		Contact::getFirstName(void) const {
	return (this->_fname);
}

std::string		Contact::getLastName(void) const {
	return (this->_lname);
}

std::string		Contact::getNickName(void) const {
	return (this->_nname);
}

std::string		Contact::getNumber(void) const {
	return (this->_phone_num);
}

std::string		Contact::getSecret(void) const {
	return (this->_secret);
}

void Contact::create_contact(void){
	std::string	buff;
	int			i = 0;

	while (i < 5){
		std::system ( "clear" );
		this->good_request(i);
		std::getline(std::cin, buff);
		if (std::cin.eof())
			break ;
		if (this->check_input(buff, i) == true){
			this->fill_the_contact(buff, i);
			i++;
		}
		else {
			std::cout << "❌ invalid entry, please try again" << std::endl;
			sleep(1);
		}
	}
	if (i == 5)
		std::cout << "✅ Contact is registered !" << std::endl;
		sleep(1);
}

void    Contact::good_request(int index){
	std::cout << std::endl << "what is her ";
	if (index == FIRST_NAME)
		std::cout << "first name";
	else if (index == LAST_NAME)
		std::cout << "last name";
	else if (index == NICKNAME)
		std::cout << "nickname";
	else if (index == PHONE_NUMBER)
		std::cout << "phone number";
	else if (index == DARKEST_SECRET)
		std::cout << "darkest secret";
	std::cout << " ?" << std::endl;
}

bool	Contact::check_input(std::string input, int index){
	if (!my_strlen(input) || is_just_blank(input) == false)
		return (false);
	if ((index == FIRST_NAME || index == LAST_NAME) && !my_isalpha(input))
		return (false);
	else if ((index == NICKNAME || index == DARKEST_SECRET) && !isprintable(input))
		return (false);
	else if ((index == PHONE_NUMBER) && !my_isdigit(input))
		return (false);
	return (true);
}

void	Contact::fill_the_contact(std::string input, int index){
	if (index == FIRST_NAME)
		this->_fname = input;
	else if (index == LAST_NAME)
		this->_lname = input;
	else if (index == NICKNAME)
		this->_nname = input;
	else if (index == PHONE_NUMBER)
		this->_phone_num = input;
	else if (index == DARKEST_SECRET)
		this->_secret = input;
}
