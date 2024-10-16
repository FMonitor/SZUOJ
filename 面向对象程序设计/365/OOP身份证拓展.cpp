#include<bits/stdc++.h>
using namespace std;
class ID {
private:
    string id;
    int capacity[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
    string valid[17] = { "1", "0", "X", "9", "8", "7", "6", "5", "4", "3", "2" };

public:
    ID(string id) 
    {
        this->id = id;
        cout << "construct ";
    }
    void print() 
    {
        cout << "ID=" << id << endl;
    }
    ID() = default;
    ~ID() 
    {
        cout << "destruct ID=" << id.substr(14, 4) << endl;
    }
    void upgrade() {
        cout << "upgrade ";
        string str = id.substr(0, 6);
        str += "19";
        str += id.substr(6, 9);
        int s = 0;
        for (int i = 0; i < 17; i++) {
            s += (str[i] - '0') * capacity[i];
        }
        s %= 11;
        str += valid[s];
        id = str;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        ID num(a);
        num.upgrade();
        num.print();
    }
    return 0;
}