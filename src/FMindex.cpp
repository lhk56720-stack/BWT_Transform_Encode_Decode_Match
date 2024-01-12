#include "../include/FMindex.h"
#include <iostream>
#include "FMindex.h"
#include <fstream>
using namespace std;
FMindex::FMindex(BwtTransform *bwt)
{
    matchStr = string();
    C = bwt->getPrefixsum();
    Occ.resize(bwt->getLen() + 1, vector<int>(4, 0));
}
FMindex::~FMindex()
{
}
void FMindex::buildOcc(BwtTransform *bwt)
{
    // 获取L列每行出现哪里个字符
    for (int i = 1; i < bwt->getLen() + 1; ++i)
    {
        if (bwt->getLastStr()[i - 1] == '$')
            continue;
        Occ[i][--bwt->getBaseMap()[bwt->getLastStr()[i - 1]]]++;
    }
    // 作累加得到Occ数组
    for (int i = 2; i < bwt->getLen() + 1; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            Occ[i][j] += Occ[i - 1][j];
        }
    }
}

void FMindex::ExatMath(BwtTransform *bwt, string line)
{
    matchStr = line;
    cout << "matchStr=" << matchStr << endl;
    int num = matchStr.size();
    char c;
    int sp, ep, i, count = 0;
    sp = 0, ep = bwt->getLen() - 1;
    i = num - 1;

    while (sp <= ep && i >= 0)
    {
        c = matchStr[i];
        cout << "ExatMath " << ++count << ":"
             << "sp=" << sp << " "
             << "ep=" << ep << endl;
        sp = C[bwt->getBaseMap()[c]] + Occ[sp][bwt->getBaseMap()[c] - 1];
        ep = C[bwt->getBaseMap()[c]] + Occ[ep + 1][bwt->getBaseMap()[c] - 1] - 1;
        i = i - 1;
    }
    cout << "--------Result--------" << endl;
    if (sp <= ep)
        cout << "Match Range:[" << sp << "," << ep << "]" << endl;
    else
        cout << "Match Fail" << endl;
}
void printOcc(BwtTransform *bwt, std::vector<std::vector<int>> Occ)
{
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
}
void FMindex::bwtDeCode(BwtTransform *bwt)
{
    buildOcc(bwt);
    // bwt->Debug("C", C);
    // printOcc(bwt, Occ);
    cout << "------ExatMath------" << endl;
    ifstream ifs("../genePool/match.txt");
    if (!ifs.is_open())
    {
        perror("match.txt open fail");
        exit(0);
    }
    string line;
    while (getline(ifs, line))
    {
        ExatMath(bwt, line);
    }
    ifs.close();
}
