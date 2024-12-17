#include <bits/stdc++.h>
using namespace std;

struct Node {
    string str = "";  
    int self = 0;     
    Node* lc = NULL;  
    Node* rc = NULL;  
};


void build(Node* root, int val, string path) {
    path += to_string(root->self) + "/";  
    if (val > root->self) {
        if (root->rc == NULL) {
            root->rc = new Node();
            root->rc->self = val;
            root->rc->str = path;  
            return;
        }
        build(root->rc, val, path);
    } else {
        if (root->lc == NULL) {
            root->lc = new Node();
            root->lc->self = val;
            root->lc->str = path;  
            return;
        }
        build(root->lc, val, path);
    }
}


string search(Node* root, int val) {
    if (root == NULL) return "NULL";
    if (root->self == val) return root->str;
    if (val > root->self) return search(root->rc, val);
    return search(root->lc, val);
}


int commonPrefixLength(const string& path1, const string& path2) {
    int len = min(path1.size(), path2.size());
    int i = 0;
    while (i < len && path1[i] == path2[i]) {
        i++;
    }
    return i;  
}

bool in(int a, string b) {
    char cmp = a + '0';
    for (int i = 0; i < b.size(); i++) {
        if (cmp == b[i])return 1;
    }
    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int m, n;
    cin >> m >> n;
    Node* root = new Node();
    cin >> root->self;

    for (int i = 1; i < n; i++) {
        int val;
        cin >> val;
        build(root, val, "");
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        string pathA = search(root, a);
        string pathB = search(root, b);
        
        if (pathA == "NULL" && pathB == "NULL") {
            cout << "ERROR: " << a << " and " << b << " are not found." << endl;
            continue;
        } else if (pathA == "NULL") {
            cout << "ERROR: " << a << " is not found." << endl;
            continue;
        } else if (pathB == "NULL") {
            cout << "ERROR: " << b << " is not found." << endl;
            continue;
        }
        if (in(a,pathB) == 1) {  
            cout << a << " is an ancestor of " << b << "." << endl;
        } else if (in(b,pathA) == 1) {  
            cout << b << " is an ancestor of " << a << "." << endl;
        } else {
            int lcpLen = commonPrefixLength(pathA, pathB);
            string commonPath = pathA.substr(0, lcpLen);
            int lcaVal = stoi(commonPath.substr(commonPath.find_last_of('/') - 1, 1));
            cout << "LCA of " << a << " and " << b << " is " << lcaVal << "." << endl;
        }
    }

    return 0;
}
