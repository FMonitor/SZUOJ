#include<bits/stdc++.h>
using namespace std;
struct Node {
    char data;
    Node* lchild;
    Node* rchild;
};

void buildPreOrder(Node*& fa, string dat, int &index) {
    if (index >= dat.size()) {
        return;
    }
    if (dat[index] == '0') {
        fa = NULL;
    } else {
        fa = new Node;
        fa->data = dat[index];
        buildPreOrder(fa->lchild, dat, ++index);
        buildPreOrder(fa->rchild, dat, ++index);
    }
}

void countLeaves(Node*& fa, int& cnt) {
    if (fa->lchild == NULL && fa->rchild == NULL) {
        cout << fa->data << endl;
        cnt++;
        return;
    }
    if (fa->lchild != NULL) {
        countLeaves(fa->lchild, cnt);
    }
    if (fa->rchild != NULL) {
        countLeaves(fa->rchild, cnt);
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
        buildPreOrder(fa, dat, index);
        int cnt = 0;
        countLeaves(fa, cnt);
        cout << cnt << endl;
        destroy(fa);
    }
}