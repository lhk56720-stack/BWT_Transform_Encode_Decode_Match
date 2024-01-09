#pragma once
#include "BwtTransform.h"
class BwMatrix : public BwtTransform
{
public:
    BwMatrix(std::string origin);
    ~BwMatrix() override;
    // 1.1通过BWT矩阵实现
    void
    buildMatrix() override;

    // 循环左移获取字符串
    std::string getNewstr(std::string str, Mode mode) override;
    // 字典序排序矩阵
    void sortMatrix() override;
    // 获取首串和尾串
    void initFLStr() override;

    void printBwt() override;

private:
    std::vector<std::string> bwtMatrix; // bwt矩阵
};