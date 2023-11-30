#include "file_replacer.hpp"

FileReplacer::FileReplacer() {}

FileReplacer::~FileReplacer() {}

void FileReplacer::replaceInFile(const char* filename, const std::string& s1, const std::string& s2)
{
    std::ifstream inputFile(filename);
    std::ostringstream outputContent;
    std::string line;

    if (!inputFile)
    {
        std::cerr << "Error when opening the input file: " << filename << std::endl;
        return;
    }

    while (std::getline(inputFile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.replace(pos, s1.length(), s2);
            pos += s2.length();
        }
        outputContent << line << '\n';
    }

    inputFile.close();

    std::string outputFileName = std::string(filename) + ".replace";
    std::ofstream outputFile(outputFileName.c_str(), std::ofstream::out);  // Utilisation de c_str() pour obtenir un const char*
    if (!outputFile)
    {
        std::cerr << "Error when opening the output file: " << outputFileName << std::endl;
        return;
    }

    outputFile << outputContent.str();
    outputFile.close();
}
