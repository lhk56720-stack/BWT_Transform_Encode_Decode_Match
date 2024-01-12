#include "../include/BwtTransform.h"
#include <iostream>
using namespace std;
#include <algorithm>
BwtTransform::BwtTransform(string origin)
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

string BwtTransform::getNewstr(string str, Mode mode)
{
    return string();
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
    return vector<int>();
}

vector<int> BwtTransform::getSA()
{
    return vector<int>();
}

void BwtTransform::Debug(string str, vector<int> &arr)
{
    cout << str << ":";
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
