#pragma once
#include <string>
#include <vector>
#include <unordered_map>
/*
1.BWT的实现
    1.1通过BWT矩阵实现
        构建矩阵 O(N²)
        排序 O(N²logN)
        总时间复杂度 O(N²+N²logN)
    1.2通过后缀数列实现
*/
const char MARKER = '$'; // 假定MARKER比任意字符都小
enum class Mode : char
{
    MATRIX,
    SUFFIX
};
class BwtTransform
{
public:
    BwtTransform(std::string origin);

    // 循环左移获取字符串
    virtual std::string getNewstr(std::string str, Mode mode) = 0;
    // 1.1通过BWT矩阵实现
    virtual void buildMatrix() = 0;
    // 字典序排序矩阵
    virtual void sortMatrix() = 0;
    // 获取首串和尾串
    virtual void initFLStr() = 0;

    virtual void printBwt() = 0;

    // 1.2通过后缀数列实现
    void buildSuffixArray();

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
    inline std::string getLastStr()
    {
        return lastStr;
    }
    inline std::string getFirstStr()
    {
        return firstStr;
    }

private:
    std::unordered_map<char, int> baseMap;
    std::string originalStr;    // 母串
    std::string newOriginalStr; // 构建后的母串
    int len;

    std::vector<int> SA;       // 后缀数组          你排第几
    std::vector<int> Rank;     // 排序数组          排第几的是谁
    std::vector<int> tmpArray; // 用于基数排序的辅助数组

protected:
    std::string lastStr;
    std::string firstStr;
};