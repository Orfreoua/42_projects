#include "phonebook.hpp"

bool	is_a_valid_string(std::string s, int index)
{
	if (!my_strlen(s) || is_just_blank(s) == false)
		return (false);
	if ((index == FIRST_NAME || index == LAST_NAME) && !my_isalpha(s))
		return (false);
	else if ((index == NICKNAME || index == DARKEST_SECRET) && !isprintable(s))
		return (false);
	else if ((index == PHONE_NUMBER) && !my_isdigit(s))
		return (false);
	return (true);
}

void	print_step(int step)
{
	if (step == FIRST_NAME)
		std::cout << "1/5: First name 👤" << std::endl;
	else if (step == LAST_NAME)
		std::cout << "2/5: Last name 👪" << std::endl;
	else if (step == NICKNAME)
		std::cout << "3/5: Nickname 😜" << std::endl;
	else if (step == PHONE_NUMBER)
		std::cout << "4/5: Phone number 📱" << std::endl;
	else if (step == DARKEST_SECRET)
		std::cout << "5/5: Darkest secret 🤫" << std::endl;
}

void    create_contact(Phonebook *phonebook)
{
	int	step = 0;

	std::cout << "remplissage contacte:\n";
	std::string line;
	while (step < 5)
	{
		print_step(step);
		std::getline(std::cin, line);
		if (is_a_valid_string(line, step))
		{
			phonebook->contact[phonebook->index].infos[step] = line;
			exit(0);
			step++;
		}
		if (std::cin.eof())
	 		exit(0);
	}
	phonebook->nb_contact++;
	
	phonebook->index++;
	if (phonebook->index == 8)
		phonebook->index = 0;
}


void	print_separator()
{
	std::cout << "+-------------------------------------------+";
	std::cout << std::endl;
}

void	print_header()
{
	print_separator();
	std::cout << "|Index     |First name|Last Name |Nickname  |";
	std::cout << std::endl;
	print_separator();
}

void	display_contact(Contact contact)
{
	int	i = 0;
	int	len = 0;
	std::cout << "|";
	while (i < 5)
	{
		while (contact.infos[i][len])
		{
			if (len == 10)
			{
				std::cout << ".";	
				break ;
			}
			std::cout << contact.infos[i][len];
			len++;
		}
		while (len++ < 10)
			std::cout << " ";
		std::cout << "|";
		i++;
		break ;
		//len = 0;
	}
	std::cout << "|" << std::endl;
}

void	print_table( Phonebook *phonebook)
{
	print_header();
	for (int i = 0; (i < phonebook->nb_contact); i++)
	{
		//if (i > 0)
		//	print_separator();
		display_contact(phonebook->contact[i]);
		print_separator();
	}
}

int	valid_number(std::string line, int nb_contact)
{
	if (line == "1" && nb_contact >= 1)
		return (true);
	else if (line == "2" && nb_contact >= 2)
		return (true);
	else if (line == "3" && nb_contact >= 3)
		return (true);
	else if (line == "4" && nb_contact >= 4)
		return (true);
	else if (line == "5" && nb_contact >= 5)
		return (true);
	else if (line == "6" && nb_contact >= 6)
		return (true);
	else if (line == "7" && nb_contact >= 7)
		return (true);
	else if (line == "8" && nb_contact == 8)
		return (true);
	else if (line == "exit" || line == "Exit")
		return (true);
	return (false);

}

void	load_informations(Phonebook *phonebook)
{
	std::string	line;

	print_table(phonebook);
	while (true)
	{
		std::getline(std::cin, line);
		if (valid_number(line, phonebook->nb_contact) == true)
			break ;
		if (std::cin.eof())
			exit(0);
	}
}

Phonebook::Phonebook(){
	/*for (int i = 0; (i < 8); i++)
		this->contact[i] = NULL;*/
}

Phonebook::~Phonebook(){

}

int main()
{
	 std::string 	line;
	 Phonebook		phonebook;

	phonebook.nb_contact = 0;
	while (true)
	{
	 	std::cout << "racine:\n";
	 	std::getline(std::cin, line);
	 	if (std::cin.eof())
	 		exit(0);
	 	if (line == "ADD")
	 		create_contact(&phonebook);
	 	else if (line == "SEARCH")
			load_informations(&phonebook);
	 	else if (line == "EXIT")
	 		exit(0);
	}
	return (0);
}