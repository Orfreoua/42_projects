#include "book.hpp"

Book::Book(int nbr) : _nb_cont(nbr), _index_cont(nbr) {
	std::cout << std::endl << UNDER << "Bienvenue dans votre annuaire" << NORM << " 📖" << std::endl;
	std::cout << "Vous pouvez écrire : " << YELL << "[ADD] [SEARCH] [EXIT]" << NORM << std::endl << std::endl;
}

Book::~Book(void) {
	std::cout << std::endl << UNDER << "Fermeture de l'annuaire" << NORM << " 📕" << std::endl;
}

void	Book::waiting_cmd(void) {
	
	std::string		buff;

	
	while (true)
	{
		if (std::cin.eof())
			return ;
		std::cout << "📝 Que souhaitez vous faire : ";
		std::getline(std::cin, buff);
		if (buff == "ADD") {
				this->_all[this->_nb_cont] = this->add_contact();
				if (this->_nb_cont < 8)
					this->_nb_cont += 1;
				if (this->_index_cont == 8)
					this->_index_cont = 0;
				else
					this->_index_cont++;
		}
		else if (buff == "SEARCH") {
			this->search_contact(this->_all, this->_nb_cont);
		}
		else if (buff == "EXIT") {
			return ;
		}
	}
}

Contact		Book::add_contact(void) {
	Contact		new_contact;

	new_contact.createContact();
	return (new_contact);
}

void		Book::search_contact(Contact phonebook[8], int nbr) {
	int				index;
	std::string		buff;

	std::cout << "🔎 Veuillez saisir l'index recherché : ";
	std::getline(std::cin, buff);
	if (std::cin.eof())
			return ;
	index = atoi(buff.c_str());
	if (buff.empty()) {
		std::cout << BL_RED << "❌ Index invalide." << NORM <<std::endl;
		return ;
	}
	if (index > nbr - 1 || !isdigit(buff.at(0)) || buff.length() > 1) {
		std::cout << BL_RED << "❌ Index invalide." << NORM <<std::endl;
		return ;
	}
	std::cout << "|" << std::setw(10) << buff << "|";
	buff = phonebook[index].getFirstName();
	if (buff.length() > 10)
		buff = resize_contact(buff);
	std::cout << std::setw(10) << buff << "|";
	buff = phonebook[index].getLastName();
	if (buff.length() > 10)
		buff = resize_contact(buff);
	std::cout << std::setw(10) << buff << "|";
	buff = phonebook[index].getNickName();
	if (buff.length() > 10)
		buff = resize_contact(buff);
	std::cout << std::setw(10) << buff << "|" << std::endl;
}

std::string		Book::resize_contact(std::string name) {

	std::string trunc;

	trunc = name.substr(0, 9);
	trunc.append(".");
	return (trunc);
}