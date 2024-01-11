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
    void ExatMath(BwtTransform *bwt);

private:
    std::vector<int> C;                // 当前字符在F列中出现的总次数
    std::vector<std::vector<int>> Occ; // Occ[i,c]表示字符c在F列中第i行前共出现的次数
};
