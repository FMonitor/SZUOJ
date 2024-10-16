#include<bits/stdc++.h>
using namespace std;

class Matrix {
private:
    int x, y;
    int** mat;
public:
    Matrix(int x, int y) {
        mat = new int* [y];
        int tmp[x][y];
        for (int i = 0; i < y; i++) {
            mat[i] = new int[x];
        }
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                cin >> tmp[i][j];
            }
        }
        cout << "before:" << endl;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                mat[j][x-i-1] = tmp[i][j];
                cout << tmp[i][j];
                if (j != y - 1) cout << " ";

            }
            cout << endl;
        }
    }
    ~Matrix() {
        for (int i = 0; i < y; i++) {
            delete[] mat[i];
        }
        delete[] mat;
    }
    void display(int x,int y) {
        cout << "after:" << endl;
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                cout << mat[i][j];
                if (j != x - 1) cout << " ";
            }
            cout << endl;
        }
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        Matrix m(x, y);
        m.display(x,y);
        if(t!=0)cout << endl;
    }
    return 0;
}