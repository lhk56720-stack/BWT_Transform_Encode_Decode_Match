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
}

string BwtTransform::getNewstr(string str)
{
    return str.substr(1) + str[0];
}
void BwtTransform::buildMatrix()
{
    string tmpStr = originalStr;
    for (int i = 0; i < len; ++i)
    {
        bwtMatrix[i] = tmpStr;
        tmpStr = getNewstr(tmpStr);
    }
}

void BwtTransform::sortMatrix()
{
    // sort(bwtMatrix[0].begin(), bwtMatrix[0].end());
    sort(bwtMatrix.begin(), bwtMatrix.end(), [](const string &a, const string &b)
         { return a[0] < b[0]; });
}

void BwtTransform::printBwt()
{
    for (int i = 0; i < len; ++i)
    {
        cout << bwtMatrix[i] << endl;
    }
}
