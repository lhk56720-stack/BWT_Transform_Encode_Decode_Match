#include "../include/BwtTransform.h"
#include "BwtTransform.h"
#include <iostream>
using namespace std;
#include <algorithm>
BwtTransform::BwtTransform(std::string origin)
{
    originalStr = origin;
    newOriginalStr = originalStr + MARKER;
    len = newOriginalStr.size();
    bwtMatrix.resize(len, string());
    lastStr = string();
    firstStr = string();
}

string BwtTransform::getNewstr(string str)
{
    return str.substr(1) + str[0];
}
void BwtTransform::buildMatrix()
{
    cout << "原始母串:" << originalStr << endl;
    cout << "构建后母串:" << newOriginalStr << endl;
    string tmpStr = newOriginalStr;
    for (int i = 0; i < len; ++i)
    {
        bwtMatrix[i] = tmpStr;
        tmpStr = getNewstr(tmpStr);
    }
    cout << "bwt矩阵:" << endl;
    printBwt();
    cout << "排序后的bwt矩阵:" << endl;
    sortMatrix();
    printBwt();
    initFLStr();
    cout << "F串:" << firstStr << endl
         << "L串:" << lastStr << endl;
}

void BwtTransform::sortMatrix()
{
    sort(bwtMatrix.begin(), bwtMatrix.end(), [&](const string &a, const string &b)
         {
            for (int i = 0; i < len;++i)
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

void BwtTransform::initFLStr()
{
    for (int i = 0; i < len; ++i)
    {
        firstStr += bwtMatrix[i][0];
        lastStr += bwtMatrix[i][len - 1];
    }
}

void BwtTransform::printBwt()
{
    for (int i = 0; i < len; ++i)
    {
        cout << bwtMatrix[i] << endl;
    }
}
