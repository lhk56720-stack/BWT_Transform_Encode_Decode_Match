#include "../include/BwtTransform.h"
#include "../include/BwMatrix.h"
#include <iostream>
using namespace std;
int main()
{
    string originalStr = "ACAACG";
    auto start = clock();
    BwtTransform *bwt = new BwMatrix(originalStr);
#if 1
    // BW矩阵
    bwt->buildMatrix();
#else
    bwt->buildSuffixArray();
#endif
    auto end = clock();
    cout << "executable time:" << static_cast<double>(end - start) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}