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
    Node* nxt = NULL;
}hashSet[12];

void Hash(int key) {
    int mol = key % 11;
    if (hashSet[mol].nxt == NULL) {
        hashSet[mol].nxt = new Node(key);
        return;
    } 
    Node* head = hashSet[mol].nxt;
    while (head->nxt != NULL) {
        head = head->nxt;
    }

    Node* tmp = new Node(key);
    head->nxt = tmp;
}

void search(int key) {
    int cnt = 1;
    int mol = key % 11;
    // cout << key << endl;
    Node* tmp = hashSet[mol].nxt;
    while (tmp != NULL && tmp->key != key) {
        // cout << mol << " " << tmp->key << " " << key;

        cnt++;
        tmp = tmp->nxt;
    }
    if (tmp == NULL) {
        cout << "error" << endl;
        Hash(key);
        return;
    }if (tmp->key == key) {
        cout << mol << ' ' << cnt << endl;
        return;
    }
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