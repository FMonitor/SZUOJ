#include<bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    int id;
    int fa;
    Node* lchild, * rchild;
};

queue<Node*> que;

void buildPreOrder(Node*& root, string& data, int& index) {
    if (index >= data.size()) {
        return;
    }
    if (data[index] == '#') {
        root = NULL;
    } else {
        root = new Node;
        root->data = data[index];
        root->id = index;
        // cout << root->data << " build left " << index << endl;
        buildPreOrder(root->lchild, data, ++index);
        // cout << root->data << " build right " << index << endl;
        buildPreOrder(root->rchild, data, ++index);
    }
}

void lvlOrder(Node* &root,int fa) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    // cout << root->lchild->data << " " << root->rchild->data << endl;
    int tmp = fa;
    cout << root->lchild << endl;
    if (root->lchild != NULL) {
        cout << "?";
        root->lchild->fa = fa + 1;
        root->lchild->id = tmp++;
        que.push(root->lchild);
    }
    if (root->rchild != NULL) {
        root->rchild->fa = fa + 1;
        root->rchild->id = tmp++;

        que.push(root->rchild);
    }
    cout << que.size();
    que.pop();
    lvlOrder(que.front(), que.front()->id);
    
}



void destroy(Node*& root) {
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
        que.push(root);
        lvlOrder(root, -1);
        destroy(root);
        cout << endl;
    }

    
    return 0;
}