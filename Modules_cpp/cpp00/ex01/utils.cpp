#include "phonebook.hpp"

int		my_strlen(std::string s)
{
	int	i = 0;

	while (s[i])
		i++;
	return (i);
}

bool	is_just_blank(std::string s)
{
	int		i = 0;
	bool	ok = false;

	while (s[i])
	{
		if (s[i] != ' ')
			ok = true;
		i++;
	}
	return (ok);
}

bool	my_isalpha(std::string s)
{
	int	i = 0;

	while (s[i])
	{
		if (!std::isalpha(s[i]) && s[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	my_isdigit(std::string s)
{
	int	i = 0;

	while (s[i])
	{
		if (!std::isdigit(s[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	isprintable(std::string s)
{
	int	i = 0;

	while (s[i])
	{
		if (!std::isdigit(s[i]) && !std::isalpha(s[i]))
			return (false);
		i++;
	}
	return (true);
}
