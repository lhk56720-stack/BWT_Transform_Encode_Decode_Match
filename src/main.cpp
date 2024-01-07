#include "../include/BwtTransform.h"
#include <iostream>
using namespace std;
int main()
{
    string originalStr = "ACAACG";
    //BW矩阵
    auto start = clock();
    BwtTransform bwt(originalStr);
    bwt.buildMatrix();
    auto end = clock();
    cout << "executable time:" << static_cast<double>(end - start) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}