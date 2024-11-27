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

int search(Node* root, int target, int times) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == target) {
        return times + 1;
    }
    if (root->data < target) {
        return search(root->rchild, target, times + 1);
    }
    if (root->data > target) {
        return search(root->lchild, target, times + 1);
    }
}

void levelOrder(Node* root) {
    if (root == NULL) return;
    levelOrder(root->lchild);
    cout << root->data << " ";
    levelOrder(root->rchild);
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
    levelOrder(root);
    cout << endl;
    while (t--) {
        int target;
        cin >> target;
        int res = search(root, target, 0);
        cout << res << endl;
    }
    return 0;
}