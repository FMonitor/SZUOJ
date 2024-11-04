#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};

struct cmp {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

priority_queue<Node*, vector<Node*>, cmp > nodes;
Node* create(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

vector<int> encoding;
string s[100];
bool flag[100];
int num[100];
int n;
void dfs(Node* root) {
    if (root->left != NULL) {
        encoding.push_back(0);
        dfs(root->left);
    } if (root->right != NULL) {
        encoding.push_back(1);
        dfs(root->right);
    }
    if(root->left == NULL && root->right == NULL) {
        string str = "";
        for (int i = 0; i < n; i++) {
            if (num[i] == root->data && !flag[i]) {
                flag[i] = true;
                for (int j = 0; j < encoding.size(); j++) {
                    str += to_string(encoding[j]);
                }
                s[i] = str;
                break;
            }
        }
    }
    encoding.pop_back();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        nodes.push(create(num[i]));
    }
    Node* head;
    while (nodes.size() > 1) {
        Node* a = nodes.top();
        nodes.pop();
        Node* b = nodes.top();
        nodes.pop();
        Node* head = create(a->data + b->data);
        head->left = a;
        head->right = b;
        nodes.push(head);
    }
    dfs(nodes.top());
    nodes.pop();
    for(int i = 0; i < n; i++) {
        cout << num[i] << "-";
        cout << s[i] << endl;
    }
    return 0;
}