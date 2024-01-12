#include "../include/FileManager.h"
#include <iostream>
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
    string tmp = string();
    while (getline(ifs, tmp))
    {
        buf += tmp;
    }
    ifs.close();
}

void FileManager::writeFile(string path, int Max)
{
    ofstream ofs(path, ios::out);
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
void FileManager::writeFile(string path, int m, int n)
{
    ofstream ofs(path, ios::out);
    if (!ofs.is_open())
    {
        perror("match.txt open fail");
        exit(0);
    }
    for (int i = 0; i < m; ++i) // 数据行数
    {
        for (int j = 0; j < n; ++j) // 每行数据的数据长度
        {
            ofs << charMap[rand() % 4];
        }
        ofs << endl;
    }
    ofs.close();
}
void FileManager::writeFile(string path, ofstream &ofs, string line, int sp, int ep, BwtTransform *bwt)
{
    static int count = 0;
    if (!ofs.is_open())
    {
        perror((getfileName(path) + "open fail!").c_str());
        exit(0);
    }
    ofs << "-----Match" << ++count << "-----" << endl
        << line << endl
        << "F Range:[" << sp << "," << ep << "]" << endl
        << "original Range:[" << bwt->getSA()[sp] << "," << bwt->getSA()[ep] << "]" << endl
        << endl;
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
