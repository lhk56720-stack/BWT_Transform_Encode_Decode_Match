#include "../include/BwtTransform.h"
#include <iostream>
using namespace std;
int main()
{
    string originalStr = "ACAACG";
    BwtTransform bwt(originalStr);
    cout << "原始母串:" << bwt.getOriginalStr() << endl;
    cout << "构建后母串:" << bwt.getNewOriginalStr() << endl;
    bwt.buildMatrix();
    cout << "bwt矩阵:" << endl;
    bwt.printBwt();
    cout << "排序后的bwt矩阵:" << endl;
    bwt.sortMatrix();
    bwt.printBwt();
    return 0;
}