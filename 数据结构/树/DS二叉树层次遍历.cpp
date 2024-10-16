#include<bits/stdc++.h>
using namespace std;
struct Node {
    char data;
    Node* lchild;
    Node* rchild;
};
vector<char> fadata;
vector<char> chidata;
bool flag;
void buildPreOrder(Node*& fa, string dat, int& index) {
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

void destroy(Node*& fa) {
    if (fa == NULL) {
        return;
    }
    destroy(fa->lchild);
    destroy(fa->rchild);
    delete fa;
}

queue<Node*> nodes;
void levelOrder(Node* fa) {
    cout << fa->data;
    if (fa->lchild != NULL) {
        nodes.push(fa->lchild);
    }
    if (fa->rchild != NULL) {
        nodes.push(fa->rchild);
    }
    nodes.pop();
    if (!nodes.empty()) {
        levelOrder(nodes.front());
    }
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
        nodes.push(fa);
        levelOrder(fa);
        cout << endl;
        destroy(fa);
    }
}