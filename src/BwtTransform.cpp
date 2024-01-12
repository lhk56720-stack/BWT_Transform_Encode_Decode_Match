#include "../include/BwtTransform.h"
#include "BwtTransform.h"
#include <iostream>
using namespace std;
#include <algorithm>
BwtTransform::BwtTransform(std::string origin)
{
    baseMap = {{'$', 0}, {'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
    originalStr = origin + MARKER;
    len = originalStr.size();
    lastStr = string();
    firstStr = string();
}

BwtTransform::~BwtTransform()
{
}

void BwtTransform::bwtEnCode()
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

vector<int> BwtTransform::getPrefixsum()
{
}

void BwtTransform::Debug(std::string str, std::vector<int> &arr)
{
    cout << str << ":";
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
