#include "contact.hpp"

/************************************************************
*				CONSTRUCTOR & DESTRUCTOR					*
 ***********************************************************/

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

/************************************************************
*					ACCESOR SET								*
 ***********************************************************/

void	Contact::setFirstName(std::string fname) {
	this->_fname = fname;
}

void	Contact::setLastName(std::string lname) {
	this->_lname = lname;
}

void	Contact::setNickName(std::string nname) {
	this->_nname = nname;
}

void	Contact::setNumber(std::string nbr) {
	this->_phone_num = nbr;
}

void	Contact::setSecret(std::string secret) {
	this->_secret = secret;
}

/****************************************************************
 *					ACCESSOR GET								*
 ***************************************************************/

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

/************************************************************
*					IS VALID STRING							*
 ***********************************************************/

int		Contact::_isValidName(std::string name)
{
	size_t		i;

	for (i = 0; i < name.length(); i++){
		if ((!isalpha(name.at(i)) && !isspace(name.at(i)) && name.at(i) != '-'))
			return (1);
	}
	return (0);
}

int		Contact::_isValidNumber(std::string number)
{
	size_t		i;

	for (i = 0; i < number.length(); i++) {
		if (!isdigit(number.at(i)) || number.length() != 10)
			return (1);
	}
	return (0);
}

/************************************************************
*					CREATE CONTACT							*
 ***********************************************************/

void	Contact::createContact(void) {
	std::string		buff;

	std::cout << std::endl << "Quel est le " << BLUE << "prénom" << NORM << " : ";
	std::getline(std::cin, buff);
	if (std::cin.eof())
			return ;
	while (_isValidName(buff) || buff.empty())
	{
		if (std::cin.eof())
			return ;
		std::cout << BL_RED << "❌ Prénom invalide, veuillez réessayer" << NORM << std::endl;
		std::cout << "Quel est le " << BLUE << "prénom" << NORM << " : ";
		std::getline(std::cin, buff);
	}
	setFirstName(buff);
	std::cout << "Quel est le " << BLUE << "nom de famille" << NORM << " : ";
	std::getline(std::cin, buff);
	if (std::cin.eof())
			return ;
	while (_isValidName(buff) || buff.empty())
	{
		if (std::cin.eof())
			return ;
		std::cout << BL_RED << "❌ Nom invalide, veuillez réessayer" << NORM << std::endl;
		std::cout << "Quel est le " << BLUE << "nom de famille" << NORM << " : ";
		std::getline(std::cin, buff);
	}
	setLastName(buff);
	std::cout << "Quel est le " << BLUE << "pseudo" << NORM << " : ";
	std::getline(std::cin, buff);
	if (std::cin.eof())
			return ;
	setNickName(buff);
	std::cout << "Quel est le " << BLUE << "numéro de téléphone" << NORM << " : ";
	std::getline(std::cin, buff);
	if (std::cin.eof())
			return ;
	while (_isValidNumber(buff) || buff.empty())
	{
		if (std::cin.eof())
			return ;
		std::cout << BL_RED << "❌ Numéro invalide, veuillez réessayer" << NORM << std::endl;
		std::cout << "Quel est le " << BLUE << "numéro de téléphone" << NORM << " : ";
		std::getline(std::cin, buff);
	}
	setNumber(buff);
	std::cout << "Quel est le " << BLUE << "secret de ce contact" << NORM << " : ";
	std::getline(std::cin, buff);
	if (std::cin.eof())
			return ;
	setSecret(buff);
	std::cout << GR << "✅ Le Contact est bien enregistré !" << NORM << std::endl << std::endl;	

}