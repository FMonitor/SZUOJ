#include<bits/stdc++.h>
using namespace std;

class CDate {
private:
    int year, month, day;
public:
    CDate(int n = 0) {
        year = n / 10000;
        month = n % 10000 / 100;
        day = n % 100;
    }
    operator int() const{
        return year * 10000 + month * 100 + day;
    }
    void Print() {
        cout << year << "年";
        if (month < 10) {
            cout << "0";
        }
        cout << month << "月";
        if (day < 10) {
            cout << "0";
        }
        cout << day << "日" << endl;
    }
};

/*******************************************/
// 主函数
int main()
{
    int t, t1, t2;
    CDate C1, C2;
    cin >> t;
    while (t--)
    {
        cin >> t1 >> t2;
        C1 = t1;
        C2 = t2;
        ((C1 > C2) ? C1 : C2).Print(); // 日期大的输出，在代码C1>C2中，会自动把C1和C2转换为整数进行比较
    }
    return 0;
}