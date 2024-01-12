#include "../include/SuffixArray.h"
#include <iostream>
using namespace std;
SuffixArray::SuffixArray(string origin) : BwtTransform(origin)
{
    SA.resize(len, 0);
    Rank.resize(len, 0);
    tmpArray.resize(len, 0);
    buckets.resize(len, 0);
    prefixSum.resize(5, 0);
}

SuffixArray::~SuffixArray()
{
}
vector<int> SuffixArray::getSA()
{
    return SA;
}
vector<int> SuffixArray::getPrefixsum()
{
    return prefixSum;
}
bool cmp(int *r, int a, int b, int len)
{
    return r[a] == r[b] && r[a + len] == r[b + len];
}
void SuffixArray::buildSuffixArray()
{
    // 第一次基数排序
    for (int i = 0; i < len; ++i)
    {
        buckets[baseMap[originalStr[i]]]++; // 统计每个碱基出现的次数
        Rank[i] = baseMap[originalStr[i]];
    }
    vector<int> abc(buckets.begin(), buckets.end());
    Debug("buckets", buckets);
    // 桶转换为前缀和数组
    for (int i = 1; i < 5; ++i)
    {
        prefixSum.at(i) = prefixSum.at(i - 1) + buckets.at(i - 1);
    }
    Debug("prefixSum", prefixSum);
    for (int i = 1; i < 5; ++i)
    {
        buckets.at(i) += buckets.at(i - 1);
    }
    Debug("buckets1", buckets);
    for (int i = len - 1; i >= 0; i--)
        SA.at(--buckets.at(Rank.at(i))) = i;
    // 倍增算法
    // Debug("SA", SA);
    int m = 5;
    for (int j = 1, p = 1; p < len; j << 1, m = p)
    {
        // 对第二关键字排序
        p = 0;
        for (int i = len - j; i < len; i++)
            tmpArray.at(p++) = i;
        for (int i = 0; i < len; i++)
            if (SA.at(i) >= j)
                tmpArray.at(p++) = SA.at(i) - j;
        // 根据第一关键字排序
        for (int i = 0; i < m; i++)
            buckets.at(i) = 0;
        for (int i = 0; i < len; i++)
            buckets.at(Rank.at(i))++;
        for (int i = 1; i < m; i++)
            buckets.at(i) += buckets.at(i - 1);
        for (int i = len - 1; i >= 0; i--)
            SA.at(--buckets.at(Rank.at(tmpArray.at(i)))) = tmpArray.at(i); // 更新sa数组
        swap(Rank, tmpArray);
        // 更新x数组
        p = 1, Rank.at(SA.at(0)) = 0;
        for (int i = 1; i < len; i++)
            Rank.at(SA.at(i)) = cmp(tmpArray.data(), SA.at(i - 1), SA.at(i), j) ? p - 1 : p++;
    }
    buckets.reserve(5);
}
void SuffixArray::initFLStr()
{
    for (int i = 0; i < len; ++i)
    {
        firstStr += originalStr[SA[i]];
        if (SA[i] != 0)
            lastStr += originalStr[SA[i] - 1];
        else
            lastStr += '$';
    }
}

void SuffixArray::bwtEnCode()
{
    cout << "母串:" << originalStr << endl;
    buildSuffixArray();
    cout << "-----SuffixArray Result-----" << endl;
    Debug("SA", SA);
    Debug("RANK", Rank);
    cout << "----------L&F----------" << endl;
    initFLStr();
    cout << "F:" << firstStr << endl
         << "L:" << lastStr << endl;
}