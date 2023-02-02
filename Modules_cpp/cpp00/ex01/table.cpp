#include "table.hpp"
#include "utils.hpp"

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
	int	len = my_strlen(buff);
	int i = 0;

	
	while (len++ < 10)
		std::cout << ' ';

	while (buff[i]){
		std::cout << buff[i];
		i++;
		if (i == 9 && buff[10]){
			std::cout << "*";
			i = 10;
			break ;
		}
	}
	std::cout << "|";
	if (end)
	{
		std::cout << std::endl;
		print_separator();
	}
}

void	print_sep_full_cont(int size, bool index)
{
	std::cout << std::endl;
	std::cout << '+';
	for (int i = 0; i < size; i++){
		std::cout << '-';
	}
	std::cout << std::endl;
	if (index == false)
	std::cout << '|';
}

void	print_spaces(int i)
{
	while (i--)
		std::cout << ' ';
	std::cout << '|';
}