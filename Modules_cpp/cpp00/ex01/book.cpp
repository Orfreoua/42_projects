#include "book.hpp"
#include "contact.hpp"
#include "utils.hpp"

Book::Book(void){
	this->_nb_cont = 0;
	this->_index_cont = 0;
}

Book::~Book(void){
	std::cout << "Fermeture de l'annuaire 📕" << std::endl;
}

void    Book::waiting_cmd(void){
	std::string	buff;

	while (true){
		std::cout << "\x1b[2J" << "\x1b[H"; // "clear" -> "retour en haut de page".
		if (std::cin.eof())
	 		return ;
		std::cout << std::endl  << "Welcome to your directory 📖" << std::endl;
		std::cout << "You can write : " << "[ADD] [SEARCH] [EXIT]" << std::endl;
		std::cout << "📝 What do you want to do : " << std::endl;
		std::getline(std::cin, buff);
		if (buff == "ADD"){
			this->_all[this->_index_cont] = this->add_contact();
			if (this->_index_cont == SIZE - 1)
				this->_index_cont = 0;
			else
				this->_index_cont++;
			if (this->_nb_cont < SIZE)
			this->_nb_cont++;
		}
		else if (buff == "SEARCH"){
			this->table_waiting_cmd(this->_all, this->_nb_cont);
		}
		else if (buff == "EXIT")
		{
			std::cout << "\x1b[2J" << "\x1b[H";
			break ;
		}
	}
}

Contact	Book::add_contact(void){
	Contact	new_contact;

	new_contact.create_contact();
	return (new_contact);
}

void	Book::table_waiting_cmd(Contact all[8], int nb_cont){
	std::string	buff;
	int			index;

	print_table(all, nb_cont);
	while (true){
		std::getline(std::cin, buff);
		if (std::cin.eof())
	 		return ;
		if (my_isdigit(buff) == true)
		{
			index = my_atoi(buff);
			if (index - 1 >= 0 &&  index - 1 < nb_cont)
				display_full_contact(all, index - 1, nb_cont);
		}
		waiting_cmd();
	}
}

void Book::print_table(Contact all[8], int nb_cont)
{
	std::cout << "\x1b[2J" << "\x1b[H"; // "clear" -> "retour en haut de page".
	if (nb_cont == 0)
	{
		std::cout << "❌ You don't have any contact \n";
		sleep(1);
		waiting_cmd();
	}
	std::cout << "🔎 Please enter the index you are looking for: \n";
	print_header();
	for (int i = 0; (i < nb_cont); i++){
		std::cout << "|";
		std::cout << "         ";
		std::cout << (i + 1) << '|';
		print_contact(all[i].getFirstName(), false);
		print_contact(all[i].getLastName(), false);
		print_contact(all[i].getNickName(), true);
	}
}

int		Book::bigger_line(Contact all[8], int index_cont)
{
	int	bigger_line;
	int	len_tmp;
	
	bigger_line = my_strlen(all[index_cont].getFirstName());
	len_tmp = my_strlen(all[index_cont].getLastName());
	if (len_tmp > bigger_line)
		bigger_line = len_tmp;
	len_tmp = my_strlen(all[index_cont].getNickName());
	if (len_tmp > bigger_line)
		bigger_line = len_tmp;
	len_tmp = my_strlen(all[index_cont].getNumber());
	if (len_tmp > bigger_line)
		bigger_line = len_tmp;
	len_tmp = my_strlen(all[index_cont].getSecret());
	if (len_tmp > bigger_line)
		return (len_tmp);
	return (bigger_line);
}

void    Book::display_full_contact(Contact all[8], int index_cont, int nb_cont){
	std::string	buff;
	int			index;
	int			size = bigger_line(all, index_cont) + 18;

	std::cout << "\x1b[2J" << "\x1b[H"; // "clear" -> "retour en haut de page".
	print_sep_full_cont(size, 0);
	std::cout << "Contact Number : " << index_cont + 1;
	print_spaces(size - 19);
	print_sep_full_cont(size, 0);
	std::cout << "First Name     : ";
	std::cout << all[index_cont].getFirstName();
	print_spaces(size - 18 - my_strlen(all[index_cont].getFirstName()));
	print_sep_full_cont(size, 0);
	std::cout << "Last Name      : ";
	std::cout << all[index_cont].getLastName();
	print_spaces(size - 18 - my_strlen(all[index_cont].getLastName()));
	print_sep_full_cont(size, 0);
	std::cout << "NickName       : ";
	std::cout << all[index_cont].getNickName();
	print_spaces(size - 18 - my_strlen(all[index_cont].getNickName()));
	print_sep_full_cont(size, 0);
	std::cout << "Phone Number   : ";
	std::cout << all[index_cont].getNumber();
	print_spaces(size - 18 - my_strlen(all[index_cont].getNumber()));
	print_sep_full_cont(size, 0);
	std::cout << "Secret         : ";
	std::cout << all[index_cont].getSecret();
	print_spaces(size - 18 - my_strlen(all[index_cont].getSecret()));
	print_sep_full_cont(size, 1);
	std::getline(std::cin, buff);
	if (std::cin.eof())
	 		return ;
	index = my_atoi(buff);
	if (index - 1 >= 0 &&  index - 1 < nb_cont)
		display_full_contact(all, index - 1, nb_cont);
	waiting_cmd();
}

