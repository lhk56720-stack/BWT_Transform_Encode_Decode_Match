#include "../include/BwtTransform.h"
#include "../include/BwMatrix.h"
#include "../include/SuffixArray.h"
#include "../include/FMindex.h"
#include <iostream>
#include <fstream>
#include <random>
#include <string.h>
using namespace std;
int MAX = 1024 * 100;
void createGenePool()
{
    char confirm;
    int number;
    while (true)
    {
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

    unordered_map<int, char> charMap = {{0, 'A'}, {1, 'T'}, {2, 'G'}, {3, 'C'}};
    fstream fs("original.txt", ios::out);
    if (!fs.is_open())
    {
        perror("original.txt open fail");
        exit(0);
    }
    for (int i = 0; i < MAX; ++i)
    {
        fs << charMap[rand() % 4];
    }
    fs.close();
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
    createGenePool();
    createMatchStr();
    ifstream ifs("../genePool/original.txt");
    if (!ifs.is_open())
    {
        perror("original.txt open fail");
        exit(0);
    }
    string originalStr = string();
    char ch;
    while (ifs.get(ch))
    {
        originalStr += ch;
    }
    ifs.close();
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