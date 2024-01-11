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
    virtual ~BwtTransform();
    virtual void bwtEnCode();
    // 循环左移获取字符串
    virtual std::string getNewstr(std::string str, Mode mode);
    // 1.1通过BWT矩阵实现
    virtual void buildMatrix();
    // 字典序排序矩阵
    virtual void sortMatrix();
    // 获取首串和尾串
    virtual void initFLStr();

    virtual void printBwt();

    // 1.2通过后缀数列实现
    virtual void buildSuffixArray();
    virtual std::vector<int> getPrefixsun();

    // Debug函数
    void Debug(std::string str, std::vector<int> &arr);

    inline std::unordered_map<char, int> getBaseMap()
    {
        return baseMap;
    }
    inline std::string getOriginalStr()
    {
        return originalStr;
    }
    inline std::string getLastStr()
    {
        return lastStr;
    }
    inline int getLen()
    {
        return len;
    }

protected:
    std::unordered_map<char, int> baseMap;
    std::string originalStr; // 母串
    std::string lastStr;     // 尾列
    std::string firstStr;    // 首列
    int len;                 // 母串长度
};