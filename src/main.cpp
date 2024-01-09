#include "../include/BwtTransform.h"
#include "../include/BwMatrix.h"
#include "../include/SuffixArray.h"
#include <iostream>
using namespace std;
int main()
{
    string originalStr = "ACAACG";
    auto start = clock();
#if 0
    // BW矩阵
    BwtTransform *bwt = new BwMatrix(originalStr);
    bwt->buildMatrix();
#else
    BwtTransform *bwt = new SuffixArray(originalStr);
    bwt->buildSuffixArray();
#endif
    auto end = clock();
    cout << "executable time:" << static_cast<double>(end - start) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}