#include "../include/FileManager.h"
#include <iostream>
#include <fstream>
using namespace std;
FileManager::FileManager() : charMap{{0, 'A'}, {1, 'T'}, {2, 'G'}, {3, 'C'}}
{
}
void FileManager::readFile(string path, string &buf)
{
    ifstream ifs(path);
    if (!ifs.is_open())
    {
        perror((getfileName(path) + "open fail!").c_str());
        exit(0);
    }
    buf = string();
    char ch;
    while (ifs.get(ch))
    {
        buf += ch;
    }
    ifs.close();
}

void FileManager::writeFile(string path, int Max)
{
    ofstream ofs(path);
    if (!ofs.is_open())
    {
        perror((getfileName(path) + "open fail!").c_str());
        exit(0);
    }
    for (int i = 0; i < Max; ++i)
    {
        ofs << charMap[rand() % 4];
    }
    ofs.close();
}
string FileManager::getfileName(string path)
{
    string fileName = string();
    for (int i = path.size(); i >= 0; i--)
    {
        if (path.at(i) == '/' || path.at(i) == '\\')
        {
            return fileName;
        }
        fileName = path.at(i) + fileName;
    }
    return fileName;
}
