#pragma once
#include <string>
#include <unordered_map>
class FileManager
{
public:
    FileManager();
    void readFile(std::string path, std::string &buf);
    void writeFile(std::string path, int Max);
    std::string getfileName(std::string path);

private:
    std::unordered_map<int, char> charMap;
};