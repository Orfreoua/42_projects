#include "file_replacer.hpp"

int main(int argc, char **argv)
{
	std::string s1;
	std::string s2;

	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	s1 = argv[2];
	s2 = argv[3];
	FileReplacer::replaceInFile(argv[1], s1, s2);
	return 0;
}
