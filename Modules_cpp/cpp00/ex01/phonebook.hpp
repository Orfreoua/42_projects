#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <string.h>
#include <iostream>
#include <cctype>

int		my_strlen(std::string s);
bool	is_just_blank(std::string s);
bool	my_isalpha(std::string s);
bool	my_isdigit(std::string s);
bool	isprintable(std::string s);

typedef enum s_sheet
{
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	DARKEST_SECRET,
}	t_sheet;

class	Contact
{
	private:
	public:

		std::string infos[5];
		/*std::string first_name;
		std::string last_name;
		std::string	nickname;
		std::string phone_number;
		std::string	darkest_secret;*/
};

class	Phonebook
{
	private:
	public:

		int index;
		int	nb_contact;
	
		Phonebook();
		~Phonebook();

		Contact	contact[8];
		int	getNb() const;
		void	setNb(int x);

		void	print(std::string a);
		void	print(int v);

		
};

#endif