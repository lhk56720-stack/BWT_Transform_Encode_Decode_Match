#include "../include/FMindex.h"
#include <iostream>
#include "FMindex.h"
using namespace std;
FMindex::FMindex(BwtTransform *bwt)
{
    bwt->buildSuffixArray();
    C = bwt->getPrefixsun();
    Occ.resize(bwt->getLen() + 1, vector<int>(4, 0));
    buildOcc(bwt);
}
FMindex::~FMindex()
{
}
void FMindex::buildOcc(BwtTransform *bwt)
{
    cout << "L列:" << bwt->getLastStr() << endl;
    // 获取L列每行出现哪里个字符
    for (int i = 1; i < bwt->getLen() + 1; ++i)
    {
        if (bwt->getLastStr()[i - 1] == '$')
            continue;
        Occ[i][--bwt->getBaseMap()[bwt->getLastStr()[i - 1]]]++;
    }
    // 作累加
    for (int i = 2; i < bwt->getLen() + 1; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            Occ[i][j] += Occ[i - 1][j];
        }
    }
    bwt->Debug("C", C);
    cout << "Occ:" << endl;
    for (int i = 0; i < bwt->getLen() + 1; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << Occ[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    ExatMath(bwt);
}

void FMindex::ExatMath(BwtTransform *bwt)
{
    string P = "ACA";
    int num = P.size();
    char c;
    int sp, ep, i;
    cout << "basemap=" << bwt->getBaseMap()[c] - 1 << endl;
    sp = 0, ep = bwt->getLen() - 1;
    i = num - 1;

    while (sp <= ep && i >= 0)
    {
        c = P[i];
        cout << "sp=" << sp << endl;
        cout << "ep=" << ep << endl;
        sp = C[bwt->getBaseMap()[c]] + Occ[sp][bwt->getBaseMap()[c] - 1];
        ep = C[bwt->getBaseMap()[c]] + Occ[ep + 1][bwt->getBaseMap()[c] - 1] - 1;
        cout << sp << " " << ep << endl;
        i = i - 1;
        cout << i << endl;
    }
    if (sp <= ep)
        printf("精准匹配范围在区间[%d,%d]", sp, ep);
    else
        printf("匹配失败");
}
