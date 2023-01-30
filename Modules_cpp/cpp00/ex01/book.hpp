#ifndef BOOK_HPP
#define BOOK_HPP

# include	"contact.hpp"
# include	"table.hpp"

# define	SIZE 8

class   Book
{
	private:
	
	int 	_nb_cont;
	int 	_index_cont;
	Contact _all[8];

	public:
	
	Book();
	~Book();

	void	waiting_cmd(void);
	Contact	add_contact(void);
	void	table_waiting_cmd(Contact all[8], int nb_nont);
	void	print_table(Contact all[8], int nb_cont);
};

#endif