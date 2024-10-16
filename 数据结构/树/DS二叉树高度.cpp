#include<bits/stdc++.h>
using namespace std;
struct Node {
    char data;
    Node* lchild;
    Node* rchild;
};
int maxdeg = 0;
void buildPreOrder(Node*& fa, string dat, int& index, int deg) {
    if (index >= dat.size()) {
        return;
    }
    if (dat[index] == '0') {
        fa = NULL;
    } else {
        fa = new Node;
        fa->data = dat[index];
        buildPreOrder(fa->lchild, dat, ++index,deg+1);
        buildPreOrder(fa->rchild, dat, ++index, deg + 1);
        maxdeg = max(deg, maxdeg);
    }
    
}

void destroy(Node*& fa) {
    if (fa == NULL) {
        return;
    }
    destroy(fa->lchild);
    destroy(fa->rchild);
    delete fa;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        string dat;
        cin >> dat;
        Node* fa;
        int index = 0;
        buildPreOrder(fa, dat, index, 1);
        cout << maxdeg << endl;
        maxdeg = 0;
        destroy(fa);
    }
}