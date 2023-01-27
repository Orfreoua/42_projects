#ifndef		BOOK_HPP
# define	BOOK_HPP

# include "contact.hpp"



class	Book {

public :

		Book(int nbr);
		~Book(void);

		void			waiting_cmd(void);
		Contact			add_contact(void);
		void			search_contact(Contact[8], int size);
		std::string		resize_contact(std::string);
private:

		int				_index_cont;
		int				_nb_cont;
		Contact 		_all[8];
		


};

#endif