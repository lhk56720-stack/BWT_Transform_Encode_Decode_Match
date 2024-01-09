#pragma once
#include "../include/BwtTransform.h"
#include <string>
class SuffixArray : public BwtTransform
{
public:
    SuffixArray(std::string origin);
    ~SuffixArray() override;
    void buildSuffixArray() override;

    void Debug(std::string str, std::vector<int> &arr);

private:
    std::string ary;           // 字符串
    std::vector<int> SA;       // 后缀数组          你排第几
    std::vector<int> Rank;     // 排序数组          排第几的是谁
    std::vector<int> tmpArray; // 用于基数排序的辅助数组
    std::vector<int> buckets;  // 存储字符种类

protected:
    int len;
};