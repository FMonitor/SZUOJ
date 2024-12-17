#include<bits/stdc++.h>
using namespace std;

struct Node {
    char self;
    int cnt;
    Node* letter[26];
    Node(char a) {
        self = a;
        cnt = 0;
        for (int i = 0; i < 26; i++) {
            letter[i] = NULL;
        }
    }
    Node() {
        self = '0';
        cnt = 0;
        for (int i = 0; i < 26; i++) {
            letter[i] = NULL;
        }
    }
};

Node* fa;

void insert(Node* root, string str, int index) {
    if (index == str.size()) {
        return;
    }
    if (root->letter[str[index] - 'a'] == NULL) {
        root->letter[str[index] - 'a'] = new Node(str[index]);
    }
    root->cnt++;
    insert(root->letter[str[index] - 'a'], str, index + 1);
}

void search(Node* root, string str, int index, int& res) {
    if (root == NULL) return;
    if (index == str.size()) {
        res = root->cnt; 
        return;
    }
    search(root->letter[str[index] - 'a'], str, index + 1, res);
}

void print(Node* root) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* now = q.front();
        q.pop();
        if (now->self != '0') cout << now->self;
        for (int i = 0; i < 26; i++) {
            if (now->letter[i] != NULL) {
                q.push(now->letter[i]);
            }
        }
    }
    cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    string read;
    Node* head = new Node();
    while (cin >> read) {
        if (read[0] >= '0' && read[0] <= '9')break;
        insert(head, read, 0);
    }
    print(head);
    int k=(int)read[0]-'0';
    while (k--) {
        string str;
        cin >> str;
        int index = 0;
        int res = 0;
        search(head, str, index, res);
        cout << res << endl;
    }
}