#include <fstream>
#include <iostream>
#include <string>

std::string read_file(const char* filename) {
    // Reading file to string
    std::ifstream file(filename, std::ios::ate);
    if (!file.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return "";
    }
    std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);
    std::string fileContent(fileSize, ' ');
    file.read(&fileContent[0], fileSize);
    file.close();
    return fileContent;
}