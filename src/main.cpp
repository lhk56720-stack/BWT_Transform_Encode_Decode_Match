#include "../include/BwtTransform.h"
#include "../include/BwMatrix.h"
#include "../include/SuffixArray.h"
#include "../include/FMindex.h"
#include "../include/FileManager.h"
#include <iostream>
#include <fstream>
#include <random>
#include <string.h>
using namespace std;
int MAX = 0;
// 选择是否重新随机生成基因库母串，是则指定串长
void iscreateGenePool()
{
    bool flag = false;
    int number;
    char *confirm; // 使用字符数组存储输入的字符串
    cout << "Whether to randomly generate the parent string ? (y/n): " << endl;
    while (true)
    {
        if (flag)
            break;
        cin >> confirm;
        // 不区分大小写地比较输入
        if (strcmp(confirm, "y") == 0 || strcmp(confirm, "Y") == 0)
        {
            while (true)
            {
                cout << "Please input a positive integer:";
                if (cin >> number && number > 0)
                {
                    flag = true;
                    MAX = number;
                    break;
                }
                else
                {
                    // 如果没有输入有效数字，则提示并清理输入流
                    cout << "Invalid input! \n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        }
        else if (strcmp(confirm, "n") == 0 || strcmp(confirm, "N") == 0)
        {
            return;
        }
        else
        {
            cout << "Invalid input!" << endl
                 << "Please enter a positive integer:";
        }
    }
}
int main()
{
    FileManager fileManger;
    // 指定母串长度需要大于子串长度
    iscreateGenePool();
    fileManger.writeFile("../genePool/original.txt", MAX);
    // 指定匹配串的行数和每行字符串长度
    // fileManger.writeFile("../genePool/match.txt", 30, 10);
    string originalStr = string();
    fileManger.readFile("../genePool/original.txt", originalStr);
    auto start = clock();
#if 0
        // BW矩阵
        BwtTransform *bwt = new BwMatrix(origion);
        bwt->buildMatrix();
#else
    // 后缀数组
    BwtTransform *bwt = new SuffixArray(originalStr);
    bwt->bwtEnCode();
#endif
    FMindex *obj = new FMindex(bwt);
    obj->bwtDeCode(bwt, fileManger);
    auto end = clock();
    cout << "executable time:" << static_cast<double>(end - start) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}