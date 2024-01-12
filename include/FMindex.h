#pragma once
#include "BwtTransform.h"
#include "BwMatrix.h"
#include "SuffixArray.h"
#include <vector>
#include <string>
class FMindex
{
public:
    FMindex(BwtTransform *bwt);
    ~FMindex();
    // 构建OCC
    void buildOcc(BwtTransform *bwt);
    // 精准匹配
    void ExatMatch(BwtTransform *bwt, std::string line);
    void bwtDeCode(BwtTransform *bwt);

private:
    std::vector<int> C;                // 保存的是每一种碱基在 F 列中的起始位置
    std::vector<std::vector<int>> Occ; // OCC[i][j]=k代表的就是第i种碱基的第j位之前出现了k次。
    std::string matchStr;              // 匹配串
    int sp, ep;
};
