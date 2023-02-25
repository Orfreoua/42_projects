#include "table.hpp"

void	print_separator()
{
	std::cout << "+-------------------------------------------+";
	std::cout << std::endl;
}

void	print_header()
{
	print_separator();
	std::cout << "|     Index|First name| Last Name|  Nickname|";
	std::cout << std::endl;
	print_separator();
}

void	print_contact(std::string buff, bool end){
	int	size = buff.size();

	while (size < 10)
	{
		std::cout << " ";
		size++;
	}
	size = 0;
	while (buff[size] && size < 9)
	{
		std::cout << buff[size];
		size++;
	}
	if (buff.size() == 10)
		std::cout << buff[9];
	else if (buff.size() > 10)
		std::cout << "*";
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