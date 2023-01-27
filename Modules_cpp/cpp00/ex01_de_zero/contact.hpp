#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <stdlib.h>
# include <string>
# include <sstream>
# include <iomanip>

# define UNDER "\033[4;29m"
# define NORM	"\033[m"
# define BL_RED "\033[5;1;31m"
# define GR		"\033[1;32m"
# define BLUE	"\033[1;3;4;34m"
# define YELL	"\033[1;33m"

class Contact
{
private:

	std::string	_fname;
	std::string	_lname;
	std::string	_nname;
	std::string	_phone_num;
	std::string _secret;

	int				_isValidName(std::string);
	int				_isValidNumber(std::string);
public:

	Contact(void);
	~Contact(void);

	void			setFirstName(std::string);
	void			setLastName(std::string);
	void			setNickName(std::string);
	void			setNumber(std::string);
	void			setSecret(std::string);
	std::string		getFirstName(void) const;
	std::string		getLastName(void) const;
	std::string		getNickName(void) const;
	std::string		getNumber(void) const;
	std::string		getSecret(void) const;

	void			createContact(void);
};

#endif
