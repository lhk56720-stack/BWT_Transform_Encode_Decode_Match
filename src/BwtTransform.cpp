#include "../include/BwtTransform.h"
#include "BwtTransform.h"
#include <iostream>
using namespace std;
#include <algorithm>
BwtTransform::BwtTransform(std::string origin)
{
    cout << "调用了BwtTransform父类" << endl;
    baseMap = {{'$', 0}, {'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
    originalStr = origin;
    newOriginalStr = originalStr + MARKER;
    len = newOriginalStr.size();

    lastStr = string();
    firstStr = string();
}

BwtTransform::~BwtTransform()
{
}

std::string BwtTransform::getNewstr(std::string str, Mode mode)
{
    return std::string();
}

void BwtTransform::buildMatrix()
{
}

void BwtTransform::sortMatrix()
{
}

void BwtTransform::initFLStr()
{
}

void BwtTransform::printBwt()
{
}

void BwtTransform::buildSuffixArray()
{
}

// void BwtTransform::buildSuffixArray()
// {
//     // cout << "原始母串:" << originalStr << endl;
//     // // cout << "构建后母串:" << newOriginalStr << endl;
//     // string tmpStr = originalStr;
//     // // 第一轮基数排序
//     // for (int i = 0; i < len; ++i)
//     // {
//     //     Rank[i] = baseMap[originalStr[i]];
//     // }
//     // cout << "第一轮基数排序:";
//     // for (int i = 0; i < len; ++i)
//     // {
//     //     cout << Rank[i] << " ";
//     // }
//     // // 倍增算法主循环
//     // for (int i = 1, p = 1; i <= len; i *= 2)
//     // {
//     //     // 合并第一第二关键字
//     //     for (int j = 0; j < len; ++j)
//     //     {
//     //         Rank[j] = Rank[p++] + Rank[j] * 10;
//     //     }
//     //     static int k = 0;
//     //     cout << "第" << k++ << "次合并：" << endl;
//     //     for (int i = 0; i < len; ++i)
//     //     {
//     //         cout << Rank[i] << " ";
//     //     }
//     //     cout << "-----" << endl;
//     //     // 排序
//     //     for (int i = 0; i < len; ++i)
//     //     {
//     //         tmpArray[i] = i;
//     //     }
//     //     sort(tmpArray.begin(), tmpArray.end(), [&](int &a, int &b)
//     //          { return Rank[a] < Rank[b]; });
//     //     Rank = tmpArray;
//     //     cout << "--排序---" << endl;
//     //     for (int i = 0; i < len; ++i)
//     //     {
//     //         cout << Rank[i] << " ";
//     //     }
//     //     cout << "-----" << endl;
//     // }
//     // for (int i = 0; i < len; ++i)
//     // {
//     //     SA[Rank[i]] = i;
//     // }

//     // cout << "Rank:";
//     // for (int i = 0; i < len; ++i)
//     // {
//     //     cout << Rank[i] << " ";
//     // }
//     // cout << endl;
//     // cout << "SA:";
//     // for (int i = 0; i < len; ++i)
//     // {
//     //     cout << SA[i] << " ";
//     // }

//     // 第一轮基数排序
// }
