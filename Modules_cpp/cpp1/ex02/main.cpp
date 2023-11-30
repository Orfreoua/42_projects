#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string str2 = "HI THIS IS BRAIN2";
    std::string* stringPTR = &str;
    std::string& stringREF = str;
    //std::string* mtPTR = NULL;
   //std::string& mtREF = NULL;
    //stringPTR = &str2;
   // stringREF = str2;
    
    // Affichage des adresses
    std::cout << "Adresse de la string en mémoire : " << &str << std::endl;
    std::cout << "Adresse stockée dans stringPTR  : " << stringPTR << std::endl;
    std::cout << "Adresse stockée dans stringREF  : " << &stringREF << std::endl;

    // Affichage des valeurs
    std::cout << "Valeur de la string             : " << str << std::endl;
    std::cout << "Valeur pointée par stringPTR    : " << *stringPTR << std::endl;
    std::cout << "Valeur pointée par stringREF    : " << stringREF << std::endl;
    
    return 0;
}
