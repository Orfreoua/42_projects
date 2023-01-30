#include "table.hpp"

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

void	print_contact(std::string buff, bool end){
	int i = 0;
	while (buff[i]){
		std::cout << buff[i];
		i++;
		if (i == 9 && buff[10] && buff[11]){
			std::cout << "*";
			i = 10;
			break ;
		}
	}
	while (i++ < 10)
		std::cout << " ";
	std::cout << "|";
	if (end)
	{
		std::cout << std::endl;
		print_separator();
	}
}
