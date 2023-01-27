#include "book.hpp"
#include "utils.hpp"

Book::Book(void){
	this->_nb_cont = 0;
	this->_index_cont = 0;
	std::cout << std::endl  << "Welcome to your directory 📖" << std::endl;
	std::cout << "You can write : " << "[ADD] [SEARCH] [EXIT]" << std::endl;
}

Book::~Book(void){
	std::cout << "Fermeture de l'annuaire 📕" << std::endl;
}

void    Book::waiting_cmd(void){
	std::string	buff;

	while (true){
		std::system ( "clear" );
		if (std::cin.eof())
	 		return ;
		std::cout << "📝 What do you want to do : " << std::endl;
		std::getline(std::cin, buff);
		if (buff == "ADD"){
			this->_all[this->_index_cont] = this->add_contact();
			if (this->_index_cont == SIZE)
				this->_index_cont = 0;
			if (this->_nb_cont < SIZE)
			this->_nb_cont++;
		}
		else if (buff == "SEARCH"){
			this->table_waiting_cmd(this->_all, this->_nb_cont);
		}
		else if (buff == "EXIT")
			break ;
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
		if (my_isdigit(buff) == true)
		{
			index = my_atoi(buff);
			if (index - 1 >= 0 &&  index - 1 < nb_cont)
				waiting_cmd();
		}
	}
}

void Book::print_table(Contact all[8], int nb_cont)
{
	print_header();
	for (int i = 0; (i < nb_cont); i++){
		std::cout << "|";
		std::cout << (i + 1);
		std::cout << "         |";
		print_contact(all[i].getFirstName(), false);
		print_contact(all[i].getLastName(), false);
		print_contact(all[i].getNickName(), true);
	}
}
