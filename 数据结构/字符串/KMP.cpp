#include<bits/stdc++.h>
using namespace std;

class myString {
private:
    string str;
    int size;
    void getNext(string p, int next[]) {
        int j = 0, k = -1;
        next[0] = -1;
        next[1] = 0;
        while (j < p.length() - 1) {
            if (k == -1 || p[j] == p[k]) {
                j++;
                k++;
                next[j] = k;
            } else {
                k=next[k];
            }
        }
    }
    int kmpFind(string p, int pos, int next[]) {
        int i = pos, j = 0;
        while ((i < size) && p.size()-j>0) {
            if (j == -1 || str[i] == p[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        if (j >= p.size()) {
            return i - j;
        } else {
            return -1;
        }
    }
public:
    myString() {
        size = 0;
        str = "";
    }
    ~myString() {
        size = 0;
        str = "";
    }
    void setVal(string s) {
        str = s;
        size = s.size();
    }
    int kmpFindSubstr(string p, int pos) {
        int i;
        int l = p.length();
        int* next = new int[l];
        getNext(p, next);
        for (i = 0; i < l; i++) {
            cout << next[i] << " ";
        }
        cout << endl;
        int v = -1;
        v = kmpFind(p, pos, next);
        delete[] next;
        return v;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s, p;
        cin >> s >> p;
        myString ms;
        ms.setVal(s);
        cout << ms.kmpFindSubstr(p, 0)+1 << endl;
    }
    return 0;
}
