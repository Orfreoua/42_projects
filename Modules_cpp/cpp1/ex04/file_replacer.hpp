#ifndef FILE_REPLACER_HPP
#define FILE_REPLACER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

class FileReplacer
{
	public:
		FileReplacer();
		~FileReplacer();

		static void replaceInFile(const char* filename, const std::string& s1, const std::string& s2);
};

#endif
