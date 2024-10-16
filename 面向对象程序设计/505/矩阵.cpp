#include <iostream>
using namespace std;
class CArray  //矩阵类
{
    int n, m;  //n行，m列
    int** data;  //存储矩阵数据
public:
    CArray() :data(nullptr) {}
    CArray(int nValue, int mValue);
    ~CArray();
    //补齐CArray的其它成员函数及实现
/********** Write your code here! **********/
    int* operator[](int index) {
        return data[index];
    }
    int operator()(int x, int y) const {
        return data[x][y];
    }
    CArray& operator=(const CArray& rhs) {
        // if (*this == rhs) {
        //     return *this;
        // }
        if (data) {
            for (int i = 0; i < n; i++) {
                delete[] data[i];
            }
            delete[] data;
        }
        data = new int* [rhs.n];
        for (int i = 0; i < rhs.n; i++) {
            data[i] = new int[rhs.m];
            for (int j = 0; j < rhs.m; j++) {
                data[i][j] = rhs.data[i][j];
            }
        }
        n = rhs.n;
        m = rhs.m;
        return *this;
    }
};

/*******************************************/
//CArray构造函数
CArray::CArray(int nValue, int mValue) : n(nValue), m(mValue) {
    // 分配n行m列空间
    data = new int* [n];
    for (int i = 0; i < n; i++) {
        data[i] = new int[m];
    }
}
//CArray析构函数
CArray::~CArray() {
    // 释放空间
    for (int i = 0; i < n; i++) {
        delete[] data[i];
    }
    delete[] data;
}
//主函数
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t;
    int n, m;
    int i, j;
    cin >> t;
    while (t--) {
        cin >> n >> m;          // 输入矩阵行n, 列m
        CArray matrixA(n, m);   // 定义matrixA对象
        for (i = 0; i < n; ++i) // 输入n行m列数据
            for (j = 0; j < m; j++)
                cin >> matrixA[i][j];
        cout << "MatrixA:" << endl;
        for (i = 0; i < n; ++i) // 输出matrixA中的数据
        {
            for (j = 0; j < m; j++) {
                cout << matrixA(i, j) << " ";
            }
            cout << endl;
        }
        cout << "MatrixB:" << endl;
        CArray matrixB;         // 定义matrixB对象
        matrixB = matrixA;      // 赋值
        for (i = 0; i < n; ++i) // 输出matrixB对象
        {
            for (j = 0; j < m; j++) {
                cout << matrixB[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}