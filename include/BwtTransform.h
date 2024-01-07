#pragma once
#include <string>
#include <vector>
/*
1.BWT的实现
    1.1通过BWT矩阵实现
        构建矩阵 O(N²)
        排序 O(N²logN)
        总时间复杂度 O(N²+N²logN)
    1.2通过后缀数列实现
*/
const char MARKER = '$'; // 假定MARKER比任意字符都小
class BwtTransform
{
public:
    BwtTransform(std::string origin);
    // 1.1通过BWT矩阵实现

    // 循环左移获取字符串
    std::string getNewstr(std::string str);
    // 构建BWT矩阵
    void buildMatrix();
    // 字典序排序矩阵
    void sortMatrix();
    // 获取首串和尾串
    void initFLStr();

    // 1.2通过后缀数列实现
    void buildSuffixArray();

    void printBwt();

    inline std::string getOriginalStr()
    {
        return originalStr;
    }
    inline std::string getNewOriginalStr()
    {
        return newOriginalStr;
    }
    inline int getLen()
    {
        return len;
    }
    inline std::vector<std::string> getBwtMatrix()
    {
        return bwtMatrix;
    }

private:
    std::string originalStr;    // 母串
    std::string newOriginalStr; // 构建后的母串
    int len;
    std::vector<std::string> bwtMatrix; // bwt矩阵
    std::string lastStr;
    std::string firstStr;
};