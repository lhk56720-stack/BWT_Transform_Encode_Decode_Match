#pragma once
#include "../include/BwtTransform.h"
#include <string>
#include <unordered_map>
#include <fstream>
class FileManager
{
public:
    FileManager();
    void readFile(std::string &buf);
    // 用于生成随机母串
    void writeFile(int Max);
    // 用于生成随机子串
    void writeFile(int m, int n);
    // 用于输出结果
    void writeFile(std::ofstream &ofs, std::string line, int sp, int ep, BwtTransform *bwt);
    // 截取文件名
    std::string getfileName(std::string path);

    // 获取文件路径
    inline std::string getOriginalPath()
    {
        return originalPath;
    }
    inline std::string getMatchPath()
    {
        return matchPath;
    }
    inline std::string getAnswerPath()
    {
        return answerPath;
    }

private:
    std::unordered_map<int, char>
        charMap;
    std::string originalPath;
    std::string matchPath;
    std::string answerPath;
};