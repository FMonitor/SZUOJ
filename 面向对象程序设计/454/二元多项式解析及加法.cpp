


// 请补充头文件、polyitem类、友元函数split和poly类实现。注意poly类的析构函数已经实现，无需再写

/********** Write your code here! **********/

#include<bits/stdc++.h>
using namespace std;

class polyitem {
private:
    int num;
    int nump;
    int type; //0x,1y
public:
    polyitem() {}
    polyitem(int num, int nump, int t) {
        this->num = num;
        this->nump = nump;
        type = t;
    }
    friend polyitem split(string item);
    friend class poly;
};
polyitem split(string item) {
    int num = 0;
    int nump = 0;
    int type = 0;
    for (int i = 0; i < item.size(); i++) {
        if (item[i] == 'x') {
            type = 0;
            if (i == 0 || item[i - 1] == '+') {
                num = 1;
            }
            else if (item[i - 1] == '-') {
                num = -1;
            }
            else {
                num = stoi(item.substr(0, i));
            }
        }
        if (item[i] == 'y') {
            type = 1;
            if (i == 0 || item[i - 1] == '+') {
                nump = 1;
            }
            else if (item[i - 1] == '-') {
                nump = -1;
            }
            else {
                nump = stoi(item.substr(0, i));
            }
        }
    }
    return polyitem(num, nump, type);
}

class poly {
private:
    polyitem* items;
    int n;
    static bool cmp(polyitem a, polyitem b) {
        if (a.type == b.type) {
            if (a.nump == b.nump) {
                return a.num > b.num;
            }
            return a.nump > b.nump;
        }
        return a.type < b.type;
    }
public:
    ~poly();
    poly() {};

    poly(string polystr) {
        items=new polyitem[100];
        int index = 1;
        int lastpos = 0;
        if(polystr[0]!='-')
        {
            polystr='+'+polystr;
        }
        for (int i = 0; i < polystr.size(); i++) {
            if (polystr[i] == '+' || polystr[i] == '-') {
                string item=polystr.substr(lastpos,i-lastpos);
                lastpos=i;
                items[index++]=split(item);
            }
        }
    }

    void polysort() {
        sort(items, items + n, cmp);
    }

    void addpoly(const poly& rhs) {
        int i = 1;
        int j = 1;
        while (i <= n && j <= rhs.n) {
            if (cmp(items[i], rhs.items[j])) {
                i++;
            }
            else if (cmp(rhs.items[j], items[i])) {
                for (int k = n; k >= i; k--) {
                    items[k + 1] = items[k];
                }
                items[i] = rhs.items[j];
                n++;
                i++;
                j++;
            }
            else {
                items[i].num += rhs.items[j].num;
                i++;
                j++;
            }
        }
        while (j <= rhs.n) {
            items[++n] = rhs.items[j++];
        }
    }

    void display() {
        for (int i = 0; i < n; i++) {
            if (items[i].num > 0) {
                cout << "+";
            }
            cout << items[i].num;
            if (items[i].type == 0) {
                cout << "x";
            }
            else {
                cout << "y";
            }
            if (items[i].nump > 1) {
                cout << "^" << items[i].nump;
            }
        }
    }
};



/*******************************************/
//poly类的析构函数
poly::~poly() {
    if (items)
        delete[] items;
}

// 主函数
int main() {
    string polystr;
    int t, m;
    string op;

    cin >> t; // 输入测试次数t

    while (t--) {
        cin >> m; // 输入m, 表示m个多项式

        poly polyres; // 初始结果多项式，项数0

        for (auto i = 0; i < m; i++) {
            cin >> polystr;         // 输入多项式串
            poly polya(polystr);    // 解析polystr串构造多项式
            polya.polysort();       // 按指数降序排序
            polya.display();        // 输出解析构造的多项式
            polyres.addpoly(polya); // polyres+=polya
        }
        polyres.display(); // 按指数降序排序输出
    }

    return 0;
}
