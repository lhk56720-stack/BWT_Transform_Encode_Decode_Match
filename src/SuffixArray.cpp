#include "../include/SuffixArray.h"
#include <iostream>
using namespace std;
#include <set>
SuffixArray::SuffixArray(std::string origin) : BwtTransform(origin)
{
    len = getLen();
    SA.resize(len, 0);
    Rank.resize(len, 0);
    tmpArray.resize(len, 0);
    buckets.resize(5, 0);
}

SuffixArray::~SuffixArray()
{
}
bool cmp(int *r, int a, int b, int len)
{
    return r[a] == r[b] && r[a + len] == r[b + len];
}
void SuffixArray::buildSuffixArray()
{
    // 第一次基数排序       //ACAACG$
    for (int i = 0; i < len; ++i)
    {
        buckets[baseMap[getNewOriginalStr()[i]]]++; // 统计每个碱基出现的次数
        Rank[i] = baseMap[getNewOriginalStr()[i]];
    }
    Debug("buckets", buckets);
    Debug("Rank", Rank);
    // 桶转换为前缀和数组
    for (int i = 1; i < 5; ++i)
    {
        buckets[i] += buckets[i - 1];
    }
    /*Debug("前缀和", buckets, 5);*/
    Debug("sum of front", buckets);
    for (int i = len - 1; i >= 0; i--)
        SA[--buckets[Rank[i]]] = i;

    Debug("SA", SA);
    // 倍增算法
    int m = 27;
    for (int j = 1, p = 1; p < len; j << 1, m = p)
    {
        // 对第二关键字排序
        p = 0;
        for (int i = len - j; i < len; i++)
            tmpArray[p++] = i;
        for (int i = 0; i < len; i++)
            if (SA[i] >= j)
                tmpArray[p++] = SA[i] - j;
        // 根据第一关键字排序
        for (int i = 0; i < m; i++)
            buckets[i] = 0;
        for (int i = 0; i < len; i++)
            buckets[Rank[i]]++;
        for (int i = 1; i < m; i++)
            buckets[i] += buckets[i - 1];
        // buckets[buckets[i]]++;
        for (int i = len - 1; i >= 0; i--)
            SA[--buckets[Rank[tmpArray[i]]]] = tmpArray[i]; // 更新sa数组

        swap(Rank, tmpArray);
        // 更新x数组
        p = 1, Rank[SA[0]] = 0;
        for (int i = 1; i < len; i++)
            Rank[SA[i]] = cmp(tmpArray.data(), SA[i - 1], SA[i], j) ? p - 1 : p++;
    }
    Debug("SA", SA);
    Debug("RANK", Rank);
}
void SuffixArray::Debug(string str, vector<int> &arr)
{
    cout << str << ":";
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}