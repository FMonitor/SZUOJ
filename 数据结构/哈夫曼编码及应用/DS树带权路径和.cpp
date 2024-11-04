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
int cnt = 0;
int sum = 0;
int arr[1000];
void prebuildtree(Node*& root, int& index, string s) {
    // cout << s[index] << endl;
    if (index >= s.size()) return;
    if (s[index] == '0')
        root = NULL;
    else {
        root = create(s[index]);
        char c = s[index];
        prebuildtree(root->left, ++index, s);
        prebuildtree(root->right, ++index, s);
        if ('A' <= c && c <= 'Z') {
            root->label = c;
            root->weight = arr[cnt++];
            // cout << c << " " << root->weight << endl;
        } else {
            // cout << c;
            if (root->left != NULL){
                root->weight += root->left->weight;
                // cout <<"+"<<root->left->weight;
            }
            if (root->right != NULL){
                root->weight += root->right->weight;
                // cout <<"+"<<root->right->weight;
            }
            sum+=root->weight;
            // cout << endl;
        }
    }
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
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Node* root = create(s[0]);
        int index = 0;
        prebuildtree(root, index, s);
        cout << sum << endl;
        cnt = 0;
        sum = 0;
    }
}