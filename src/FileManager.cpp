#include "../include/FileManager.h"
#include <iostream>
using namespace std;
FileManager::FileManager() : charMap{{0, 'A'}, {1, 'T'}, {2, 'G'}, {3, 'C'}}
{
#ifdef _WIN32
    // Windows 下的路径设置
    originalPath = "..\\genePool\\original.txt";
    matchPath = "..\\genePool\\match.txt";
    answerPath = "..\\genePool\\answer.txt";
#else
    // Linux 下的路径设置
    originalPath = "../genePool/original.txt";
    matchPath = "../genePool/match.txt";
    answerPath = "../genePool/answer.txt";
#endif
}
void FileManager::readFile(string &buf)
{
    ifstream ifs(originalPath);
    if (!ifs.is_open())
    {
        perror((getfileName(originalPath) + " open fail!").c_str());
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

void FileManager::writeFile(int Max)
{
    ofstream ofs(originalPath, ios::out);
    if (!ofs.is_open())
    {
        perror((getfileName(originalPath) + " open fail!").c_str());
        exit(0);
    }
    for (int i = 0; i < Max; ++i)
    {
        ofs << charMap[rand() % 4];
    }
    ofs.close();
}
void FileManager::writeFile(int m, int n)
{
    ofstream ofs(matchPath, ios::out);
    if (!ofs.is_open())
    {
        perror((getfileName(matchPath) + " open fail!").c_str());
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
void FileManager::writeFile(ofstream &ofs, string line, int sp, int ep, BwtTransform *bwt)
{
    static int count = 0;
    if (!ofs.is_open())
    {
        perror((getfileName(answerPath) + " open fail!").c_str());
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
    for (int i = path.size() - 1; i >= 0; i--)
    {
        if (path.at(i) == '/' || path.at(i) == '\\')
        {
            return fileName;
        }
        fileName = path.at(i) + fileName;
    }
    return fileName;
}
