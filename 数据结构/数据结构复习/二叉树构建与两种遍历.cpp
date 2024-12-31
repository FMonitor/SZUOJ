#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* lc;
    Node* rc;
    char val;
};

void buildPreOrder(Node*&root,string str, int &index) {
    if (index > str.size() || str[index-1]=='0') {
        return;
    }
    root = new Node();
    root->val = str[index - 1];
    buildPreOrder(root->lc, str, ++index);
    buildPreOrder(root->rc, str, ++index);
}

void preOrder(Node* root) {
    if (root == NULL)return;
    cout << root->val;
    preOrder(root->lc);
    preOrder(root->rc);
}

void levelOrder(Node* root) {
    if (root == NULL)return;
    levelOrder(root->lc);
    cout << root->val;
    levelOrder(root->rc);
}

void rearOrder(Node* root) {
    if (root == NULL)return;
    rearOrder(root->lc);
    rearOrder(root->rc);
    cout << root->val;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Node* root;
        int index = 1;
        buildPreOrder(root, str, index);
        levelOrder(root);
        cout << endl;
        rearOrder(root);
        cout << endl;
    }
    return 0;
}