#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* lc;
    Node* rc;
    int dat;
    int index;
    Node(int n, Node* lc, Node* rc,int ind) {
        dat = n;
        this->lc = lc;
        this->rc = rc;
        index = ind;
    }
};
struct cmp {
    bool operator()(Node* a, Node* b) {
        if (a->dat == b->dat) {
            return a->index > b->index;
        }
        return a->dat > b->dat;
    }
};


int arr[1000];
int n;
vector<int>res[1000];

Node* build() {
    priority_queue<Node*, vector<Node*>, cmp > pq;
    for (int i = 1; i <= n; i++) {
        pq.push(new Node(arr[i], NULL, NULL,i));
    }
    while (1) {
        Node* a = pq.top();
        pq.pop();
        if (pq.empty()) {
            return a;
        }
        Node* b = pq.top();
        pq.pop();
        Node* tmp = new Node(a->dat + b->dat, a, b,0);
        pq.push(tmp);
        // cout << a->dat << " " << b->dat << endl;
    }
}

void search(Node* root, int index) {
    if (root == NULL) {
        return;
    }
    // cout << root->dat << endl;
    if (root->dat == arr[index] && root->index==index) {
        for (int i = 0; i < res[index].size(); i++) {
            cout << res[index][i];
        }
        return;
    }
    res[index].push_back(0);
    search(root->lc, index);
    res[index].pop_back();
    res[index].push_back(1);
    search(root->rc, index);
    res[index].pop_back();
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    Node* root = build();
    // cout << root->dat << " " << root->lc->dat << " " << root->rc->dat<<endl;
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << "-";
        search(root, i);
        cout << endl;
    }
}