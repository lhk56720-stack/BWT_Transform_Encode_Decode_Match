#pragma once
#include "../include/BwtTransform.h"
#include <string>
class SuffixArray : public BwtTransform
{
public:
    SuffixArray(std::string origin);
    ~SuffixArray() override;
    // 构建后缀数组
    void buildSuffixArray() override;
    // 获取首串和尾串
    void initFLStr() override;

    std::vector<int> getPrefixsum() override;
    void bwtEnCode() override;

private:
    std::string ary;            // 字符串
    std::vector<int> SA;        // 后缀数组          排序后你在排序前的下标
    std::vector<int> Rank;      // 排序数组          排序前你在排序后的下标
    std::vector<int> tmpArray;  // 用于基数排序的辅助数组
    std::vector<int> buckets;   // 存储字符种类
    std::vector<int> prefixSum; // 存储字符第一次出现在F列中的位置
    int MM[1024];
};