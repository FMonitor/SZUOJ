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
int arr[1000];
void prebuildtree(Node*& root, int& index, string s) {
    // cout << s[index] << endl;
    if (index >= s.size()) return;
    if (s[index] == '0')
        root = NULL;
    else {
        root = create(s[index]);
        char c = s[index];
        root->label = c;
        root->weight = arr[cnt++];
        // cout << c << " " << root->weight << endl;
        prebuildtree(root->left, ++index, s);
        prebuildtree(root->right, ++index, s);
        
    }
}

int dfs(Node* root, int maxsum) {
    if (root == NULL) return maxsum;
    if (root->left == NULL && root->right == NULL) {
        return max(maxsum, root->weight);
    }
    maxsum+=max(dfs(root->left, maxsum), dfs(root->right, maxsum))+root->weight;
    return maxsum;
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
        int maxsum = 0;
        
        cout << dfs(root, maxsum) << endl;
        cnt = 0;
    }
}