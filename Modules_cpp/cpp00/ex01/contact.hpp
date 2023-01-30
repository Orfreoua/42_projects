#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <stdlib.h>
# include <string>
# include <sstream>
# include <iomanip>
# include <unistd.h>

typedef enum s_sheet
{
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	DARKEST_SECRET,
}	t_sheet;

class   Contact
{
	private:
	
	std::string	_fname;
	std::string	_lname;
	std::string	_nname;
	std::string	_phone_num;
	std::string _secret;
	
	public:

	Contact();
	~Contact();

	void    		create_contact(void);
	void    		good_request(int index);
	bool			check_input(std::string input, int index);
	void			fill_the_contact(std::string input, int index);

		std::string		getFirstName(void) const;
		std::string		getLastName(void) const;
		std::string		getNickName(void) const;
		std::string		getNumber(void) const;
		std::string		getSecret(void) const;
};
#endif