#include "FileManager.h"
#include <fstream>
#include <iostream>

std::vector<std::string> FileManager::readFile(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file " << filename << std::endl;
    }
    return lines;
}

void FileManager::writeFile(const std::string& filename, const std::vector<std::string>& lines) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& line : lines) {
            file << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file " << filename << std::endl;
    }
}
