#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>

class FileManager {
public:
    static std::vector<std::string> readFile(const std::string& filename);
    static void writeFile(const std::string& filename, const std::vector<std::string>& lines);
};

#endif // FILEMANAGER_H
