#include<bits/stdc++.h>
using namespace std;
struct Node {
    int weight;
    char label;
    Node* left, * right;
};

Node* create(char label) {
    Node* node = new Node;
    node->weight = 0;
    node->label = label;
    node->left = node->right = NULL;
    return node;
}

void buildpreOrderReverse(Node*& root, int& index, string s) {
    if (index >= s.size()) return;
    if (s[index] == '#')
        root = NULL;
    else {
        root = create(s[index]);
        buildpreOrderReverse(root->right, ++index, s);
        buildpreOrderReverse(root->left, ++index, s);
    }
}

void preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->label << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->label << " ";
    inOrder(root->right);
}

void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        cout << node->label <<" ";
        if (node->left != NULL) q.push(node->left);
        if (node->right != NULL) q.push(node->right);
    }
}

void backOrder(Node* root) {
    if (root == NULL) return;
    backOrder(root->left);
    backOrder(root->right);
    cout << root->label << " ";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (s == "#") {
            cout << "NULL\nNULL\nNULL\nNULL\n";
            continue;
        }
        int index = 0;
        Node* root = create(s[0]);
        buildpreOrderReverse(root, index, s);
        preOrder(root);
        cout << endl;
        inOrder(root);
        cout << endl;
        backOrder(root);
        cout << endl;
        levelOrder(root);
        cout << endl;
    }
}