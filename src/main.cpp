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
int MAX = 1024 * 100;
void createGenePool()
{
    bool flag = false;
    char confirm;
    int number;
    while (true)
    {
        if (flag)
            break;
        cout << "Whether to randomly generate the parent string ? (y/n): " << endl;
        cin >> confirm;
        confirm = tolower(confirm); // 将字符转换为小写以简化判断
        if (confirm == 'y')
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
                    cout << "Invalid input! Please enter a positive integer:\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        }
        else if (confirm == 'n')
        {
            return;
        }
        else
        {
            cout << "Invalid input!Please input (y/n):\n";
            cin.clear();
            // 需要忽略掉错误输入后的剩余输入，包括换行符
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void createMatchStr()
{
    ofstream ofs("../genePool/match.txt", ios::out);
    if (!ofs.is_open())
    {
        perror("match.txt open fail");
        exit(0);
    }
    unordered_map<int, char> charMap = {{0, 'A'}, {1, 'T'}, {2, 'G'}, {3, 'C'}};
    for (int i = 0; i < 20; ++i) // 数据行数
    {
        for (int j = 0; j < 10; ++j) // 每行数据的数据长度
        {
            ofs << charMap[rand() % 4];
        }
        ofs << endl;
    }
    ofs.close();
}
int main()
{
    FileManager fileManger;
    createGenePool();
    fileManger.writeFile("../genePool/original.txt", MAX);
    // createMatchStr();
    string originalStr = string();
    fileManger.readFile("../genePool/original.txt", originalStr);
    auto start = clock();
#if 0
        // BW矩阵
        BwtTransform *bwt = new BwMatrix(origion);
        bwt->buildMatrix();
#else
    BwtTransform *bwt = new SuffixArray(originalStr);
    bwt->bwtEnCode();
#endif
    FMindex *obj = new FMindex(bwt);
    obj->bwtDeCode(bwt);
    auto end = clock();
    cout << "executable time:" << static_cast<double>(end - start) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}