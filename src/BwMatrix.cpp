#pragma once
#include "../include/BwMatrix.h"
#include <iostream>
using namespace std;
#include <algorithm>
BwMatrix::BwMatrix(std::string origin) : BwtTransform(origin)
{
    cout << "调用了BW矩阵子类" << endl;
    bwtMatrix.resize(getLen(), string());
}
BwMatrix::~BwMatrix()
{
}
void BwMatrix::buildMatrix()
{
    cout << "原始母串:" << getOriginalStr() << endl;
    cout << "构建后母串:" << getNewOriginalStr() << endl;
    string tmpStr = getNewOriginalStr();
    for (int i = 0; i < getLen(); ++i)
    {
        bwtMatrix[i] = tmpStr;
        tmpStr = getNewstr(tmpStr, Mode::MATRIX);
    }
    cout << "bwt矩阵:" << endl;
    printBwt();
    cout << "排序后的bwt矩阵:" << endl;
    sortMatrix();
    printBwt();
    initFLStr();
    cout << "F串:" << getFirstStr() << endl
         << "L串:" << getLastStr() << endl;
}

std::string BwMatrix::getNewstr(std::string str, Mode mode)
{
    if (mode == Mode::MATRIX)
    {
        return str.substr(1) + str[0];
    }
    else if (mode == Mode::SUFFIX)
    {
        return str.substr(1);
    }
}

void BwMatrix::sortMatrix()
{
    sort(bwtMatrix.begin(), bwtMatrix.end(), [&](const string &a, const string &b)
         {
            for (int i = 0; i < getLen();++i)
            {
            if(a[i]<b[i])
            {
                return true;
            }
            else if(a[i]>b[i])
            {
                return false;
            }
            }
            return true; });
}

void BwMatrix::initFLStr()
{
    for (int i = 0; i < getLen(); ++i)
    {
        firstStr += bwtMatrix[i][0];
        lastStr += bwtMatrix[i][getLen() - 1];
    }
}

void BwMatrix::printBwt()
{
    for (int i = 0; i < getLen(); ++i)
    {
        cout << bwtMatrix[i] << endl;
    }
}
