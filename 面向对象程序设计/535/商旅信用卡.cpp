#include<bits/stdc++.h>
using namespace std;
class vipcard {
protected:
    int pnum;
    double pscore;
    //通过会员卡下订单,按订单金额累计旅程积分
public:
    vipcard() {
        pnum = 0;
        pscore = 0;
    }
    vipcard(int nn,double sn) {
        pnum = nn;
        pscore = sn;
    }
};
class ccard {
protected:
    int cnum;
    string name;
    double cscore;
    int deb;
    double bill;
public:
    ccard() {
        deb = 0;
        cscore = 0;
        cnum = 0;
        name = "null";
        bill = 0;
    }
    ccard(int nn, string s, int dn) {
        cnum = nn;
        name = s;
        deb = dn;
    }
    bool purchase(double m) {
        if (m + bill > deb) {
            return 0;
        }
        bill += m;
        cscore += m;
        return 1;
    }
    void payback(double m) {
        if (bill < m) {
            return;
        }
        bill -= m;
        cscore -= m;
    }
};
class comcard : public vipcard, public ccard {
public:
    comcard() {
        pnum = 0;
        cnum = 0;
        name = "null";
        deb = 0;
        bill = 0;
        cscore = 0;
        pscore = 0;
    }
    comcard(int pn, int cn, string s, int dn) {
        pnum = pn;
        cnum = cn;
        name = s;
        deb = dn;
    }
    void trans(int m) {
        if(m<=cscore)
        pscore += m/2;
        cscore -=m;
    }
    void com_purchase(double m) {
        if (purchase(m)) {
            pscore += m;
        }
    }
    void print() {
        cout << pnum << " " << (int)pscore << endl;
        cout << cnum << " " << name << " " << bill << " " << (int)cscore << endl;
        
    }

};
int main() {
    int pnum, cnum, deb;
    string name;
    int t;
    cin >> pnum >> cnum >> name >> deb >> t;
    comcard card(pnum, cnum, name, deb);
    while (t--) {
        char type;
        double num;
        cin >> type >> num;
        if (type == 'o') {
            card.com_purchase(num);
        } else if (type == 'c') {
            card.purchase(num);
        } else if (type == 'q') {
            card.payback(num);
        } else {
            card.trans(num);
        }
    }
    card.print();
    return 0;
}