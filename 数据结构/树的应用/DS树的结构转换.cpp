#include<bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    int id;
    int fa;
    Node* lchild, * rchild;
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
        root->id = index;
        // cout << root->data << " build left " << index << endl;
        buildPreOrder(root->lchild, data, ++index);
        // cout << root->data << " build right " << index << endl;
        buildPreOrder(root->rchild, data, ++index);
    }
}
queue<Node*> que;
//使用层次遍历的方式，更新节点编号

void lvlOrderID(Node* root, int id) {
    if (root == NULL) {
        return;
    }
    int index = 0;
    que.push(root);
    while (!que.empty()) {
        Node* curr = que.front();
        // cout << curr->data << " " << index<<endl;
        curr->id = index++;
        que.pop();
        if (curr->lchild != NULL) {
            // cout << " build left " << curr->lchild->data << endl;
            que.push(curr->lchild);
        }
        if (curr->rchild != NULL) {
            // cout << " build right " << curr->rchild->data << endl;
            que.push(curr->rchild);
        }
    }
}

queue<char> storedata;
queue<int> storefa;
//使用层次遍历的方式，输出节点的值和父节点编号
void lvlOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    que.push(root);
    while (!que.empty()) {
        Node* curr = que.front();
        que.pop();
        if (curr->lchild != NULL) {
            storedata.push(curr->lchild->data);
            storefa.push(curr->id);
            que.push(curr->lchild);
        }
        if (curr->rchild != NULL) {
            storedata.push(curr->rchild->data);
            storefa.push(curr->id);
            que.push(curr->rchild);
        }
    }
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
        lvlOrderID(root, -1);
        cout << root->data;
        lvlOrder(root);
        while (!storedata.empty()) {
            cout << " " << storedata.front();
            storedata.pop();
        }
        cout << endl << -1;
        while (!storefa.empty()) {
            cout << " " << storefa.front();
            storefa.pop();
        }
        cout << endl;
        destroy(root);

    }

    
    return 0;
}