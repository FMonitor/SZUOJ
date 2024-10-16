#include<bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    Node *lchild, *rchild;
};

void buildPreOrder(Node*& root, string& data, int& index) {
    if (index >= data.size()) {
        return;
    }
    if (data[index] == '#') {
        root = NULL;
    } else {
        root = new Node;
        root->data = data[index];
        // cout << root->data << " build left " << index << endl;
        buildPreOrder(root->lchild, data, ++index);
        // cout << root->data << " build right " << index << endl;
        buildPreOrder(root->rchild, data, ++index);
    }
}

void preOrder(Node* &root) {
    if (root == NULL) {
        return;
    }
    cout << root->data;
    preOrder(root->lchild);
    preOrder(root->rchild);
}

void inOrder(Node* &root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->lchild);
    cout << root->data;
    inOrder(root->rchild);
}

void postOrder(Node* &root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->lchild);
    postOrder(root->rchild);
    cout << root->data;
}

void destroy(Node* &root) {
    if (root == NULL) {
        return;
    }
    destroy(root->lchild);
    destroy(root->rchild);
    delete root;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        string data;
        cin >> data;
        Node* root;
        int index = 0;
        buildPreOrder(root, data, index);
        preOrder(root);
        cout << endl;
        inOrder(root);
        cout << endl;
        postOrder(root);
        cout << endl;
        destroy(root);
    }
    return 0;
}