#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* lchild = NULL, * rchild = NULL;
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

Node* search(Node* root, int target) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == target) {
        return root;
    }
    if (root->data < target) {
        return search(root->rchild, target);
    }
    if (root->data > target) {
        return search(root->lchild, target);
    }
    return NULL;
}

void levelOrder(Node* root) {
    if (root == NULL) return;
    levelOrder(root->lchild);
    cout << root->data << " ";
    levelOrder(root->rchild);
}

Node* findClosest(Node* root) {
    while (root->lchild != NULL) {
        root = root->lchild;
    }
    return root;
}

void delNode(Node*& root, int target) {
    if (root == NULL) return;
    if (target > root->data) {
        delNode(root->rchild, target);
    } else if (target < root->data) {
        delNode(root->lchild, target);
    } else {
        if (root->lchild == NULL) {
            Node* tmp = root->rchild;
            delete root;
            root = tmp;
        } else if (root->rchild == NULL) {
            Node* tmp = root->lchild;
            delete root;
            root = tmp;
        } else {
            Node* closet = findClosest(root->rchild);
            root->data = closet->data;
            delNode(root->rchild, closet->data);
        }
    }

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif 
    Node* root = NULL;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            root = insert(root, tmp);
        }
        int m;
        cin >> m;
        levelOrder(root);
        cout << endl;
        while (m--) {
            int target;
            cin >> target;
            delNode(root, target);
            levelOrder(root);
            cout << endl;
        }
    }

    return 0;
}