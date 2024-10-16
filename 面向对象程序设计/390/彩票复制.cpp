#include<bits/stdc++.h>
using namespace std;
class lottery {
private:
    int group1[6];
    int num = 0;
    int** groupn;
    bool flag;
public:
    lottery(int* arr, int Num) {
        for (int i = 0;i < 6;i++) group1[i] = arr[i];
        num = Num;
        flag = 0;
    }
    lottery(const lottery& lot) {
        for (int i = 0;i < 6;i++) group1[i] = lot.group1[i];
        num = lot.num;
        groupn = new int* [num];
        for (int i = 0;i < num;i++) groupn[i] = new int[6];
        for (int i = 0;i < num;i++) {
            for (int j = 1;j < 6;j++) {
                if (!i) {
                    groupn[i][0] = group1[5] + 1;
                    groupn[i][j] = group1[j - 1] + 1;
                } else {
                    groupn[i][0] = groupn[i - 1][5] + 1;
                    groupn[i][j] = groupn[i - 1][j - 1] + 1;
                }
            }
        }
        flag = 1;
    }
    ~lottery() {
        if (flag) {
            for (int i = 0;i < num;i++)  delete[]groupn[i];
            delete[]groupn;
        }
    }
    void print() {
        for (int i = 0;i < 6;i++) {
            if (i) cout << " ";
            cout << group1[i];
        }
        cout << endl;
        for (int i = 0;i < num;i++) {
            for (int j = 0;j < 6;j++) {
                if (j) cout << " ";
                cout << groupn[i][j];
            }
            cout << endl;
        }
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int arr[6];
        for (int i = 0;i < 6;i++) cin >> arr[i];
        int num;
        cin >> num;
        lottery lot(arr, num);
        lottery sec(lot);
        sec.print();
    }
    return 0;
}