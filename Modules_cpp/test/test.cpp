#include "test.hpp"

int	Test::getNb() const {
	return _nb;
}
void	Test::setNb(int x) {
	this->_nb = x;
}

Test::Test() {
	this->_nb = 42;
}

Test::Test(int x) {
	this->_nb = x;
}

Test::Test(char *s){

}

Test::Test(std::string){

}

Test::~Test() {

}

void	Test::print(std::string a) {
	std::cout << "Appel de la fonction avec string en parametre: " << a << std::endl;
}

void	Test::print(int v) {
	std::cout << "Appel de la fonction avec int en parametre: " << v << std::endl;
}

int main(void)
{
    Test t;

	t.print("salut");
	t.print(t.getNb());
    return (0);
}
