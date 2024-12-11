#include<bits/stdc++.h>
using namespace std;

struct Node {
    char val;
    Node* lc;
    Node* rc;
    int deepl;
    int deepr;
    Node() {
        val = '0';
        lc = NULL;
        rc = NULL;
        deepl = 0;
        deepr = 0;
    }
    Node(char val) {
        this->val = val;
        lc = NULL;
        rc = NULL;
        deepl = 0;
        deepr = 0;
    }
}node[1000];

string input;
int ind;
int len;
queue<Node*> q;

void build() {
    while (!q.empty()) {
        Node* now = q.front();
        q.pop();
        if (input[ind] == '0' || ind == len) {
            continue;
        }
        now = new Node(input[ind++]);
        q.push(now->lc);
        q.push(now->rc);
    }
}

void postOrder(Node* root, int deep) {
    if (root == NULL) return;
    postOrder(root->lc, deep + 1);
    postOrder(root->rc, deep + 1);
    root->deepl = max(root->lc->deepl, root->rc->deepr) + 1;
    root->deepr = max(root->rc->deepl, root->rc->deepr) + 1;
    cout << root->val << " " << root->deepl - root->deepr << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif  
    int t;
    cin >> t;
    while (t--) {
        cin >> len;
        cin >> input;
        Node* root = NULL;
        q.push(root);
        build();
        int deep = 0;
        postOrder(root, deep);
    }
    return 0;
}