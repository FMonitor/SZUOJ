#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    int index;
    Node* right;
    char label;
};
Node *create(int data, char label,int index) {
    Node *node = new Node;
    node->data = data;
    node->label = label;
    node->index = index;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct cmp {
    bool operator()(Node* a, Node* b) {
        if (a->data == b->data) {
            return a->index > b->index;
        }
        return a->data > b->data;
    }
};
bool flag[100];
string s[100];
char input[100];
map<char, string> encode;
int n;
int arr[100];   
priority_queue<Node*, vector<Node*>, cmp> nodes;
vector<int> encoding;
void dfs(Node* root) {
    if (root->left != NULL) {
        encoding.push_back(0);
        dfs(root->left);
    }
    if (root->right != NULL) {
        encoding.push_back(1);
        dfs(root->right);
    }
    if (root->left == NULL && root->right == NULL) {
        string str = "";
        for (int i = 0; i < n; i++) {
            if (arr[i] == root->data && !flag[i]) {
                flag[i]=true;
                for (int j = 0; j < encoding.size(); j++) {
                    str += to_string(encoding[j]);
                }
                s[i] = str;
                encode[input[i]] = str;
                break;
            }
        }
    }
    encoding.pop_back();
}
int cnt = 0;
void decode(string codestr) {
    string res = "";
    Node* root = nodes.top();
    for (int i = 0; i < codestr.size(); i++) {
        cnt++;
        if (codestr[i] == '0') {
            root = root->left;
            // cout << "left" << endl;
        } else {
            root = root->right;
            // cout << "right" << endl;
        }
        if (root->left == NULL && root->right == NULL) {
            res += root->label;
            // cout << res << endl;
            root = nodes.top();
            cnt = 0;
        }
        if ((i == codestr.size() - 1 && cnt) ) {
            res = "error";
        }
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> input[i];
        nodes.push(create(arr[i], input[i],i));
    }
    int m = n;
    while (nodes.size() > 1) {
        Node* a = nodes.top();
        nodes.pop();
        Node* b = nodes.top();
        nodes.pop();
        Node* head = create(a->data + b->data, ' ',m++);
        head->left = a;
        head->right = b;
        nodes.push(head);
    }
    dfs(nodes.top());

    // for(auto it = encode.begin(); it != encode.end(); it++) {
    //     cout << it->first << " " << it->second << endl;
    // }

    int count;
    cin >> count;
    while(count--) {
        string codestr;
        cin >> codestr;
        decode(codestr);
    }
}
