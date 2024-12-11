#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* nxt;
    Node() {
        key = 0;
        nxt = NULL;
    }
    Node(int key) {
        this->key = key;
        nxt = NULL;
    }
};
struct head {
    Node* nxt=NULL;
}hashSet[12];

void Hash(int key) {
    int mol = key % 11;
    Node* tmp = new Node(key);
    tmp->nxt = hashSet->nxt;
    hashSet->nxt = tmp;
}

void search(int key) {
    int cnt = 1;
    int mol = key % 11;
    cout << mol << endl;
    Node* tmp = hashSet[mol].nxt;
    while (tmp->key != key) {
        if (tmp == NULL) {
            cout << "error" << endl;
            Hash(key);
            return;
        }
        cnt++;
        tmp = tmp->nxt;
    }
    cout << mol << ' ' << cnt << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif 
    int n;
    cin >> n;
    int keys[n];
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
        Hash(keys[i]);
    }
    int k;
    cin >> k;
    while (k--) {
        int query;
        cin >> query;
        search(query);
    }
    return 0;
}