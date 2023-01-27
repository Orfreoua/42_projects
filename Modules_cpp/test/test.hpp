#ifndef TEST_HPP
#define TEST_HPP

#include <string>
#include <string.h>
#include <iostream>
#include <cctype>

class	Test
{
	private:
    int _nb;

	public:

		Test();
		~Test();

        Test(char *s);
        Test(std::string);
        Test(int x);

		int	getNb() const;
		void	setNb(int x);
        void    setNb();

		void	print(std::string a);
		void	print(int v);
};

#endif