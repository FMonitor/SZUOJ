#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *lchild, *rchild;
};

Node* insert(Node* root, int x) {
    // cout << x;
    if (root == NULL) {
        root = new Node;
        root->data = x;
        root->lchild = root->rchild = NULL;
        return root;
    } else {
        if (x < root->data) {
            root->lchild = insert(root->lchild, x);
        } else if (x > root->data) {
            root->rchild = insert(root->rchild, x);
        }
    }
    return root;
}

void preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->lchild);
    preOrder(root->rchild);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif 
    Node* root = NULL;
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        root = insert(root, tmp);
    }
    int t;
    cin >> t;
    preOrder(root);
    cout << endl;
    while (t--) {
        int tmp;
        cin >> tmp;
        root=insert(root, tmp);
        preOrder(root);
        cout << endl;
    }
    return 0;
}