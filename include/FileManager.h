#pragma once
#include "../include/BwtTransform.h"
#include <string>
#include <unordered_map>
#include <fstream>
class FileManager
{
public:
    FileManager();
    void readFile(std::string path, std::string &buf);
    // 用于生成随机母串
    void writeFile(std::string path, int Max);
    // 用于生成随机子串
    void writeFile(std::string path, int m, int n);
    // 用于输出结果
    void writeFile(std::string path, std::ofstream &ofs, std::string line, int sp, int ep, BwtTransform *bwt);
    std::string getfileName(std::string path);

private:
    std::unordered_map<int, char> charMap;
};