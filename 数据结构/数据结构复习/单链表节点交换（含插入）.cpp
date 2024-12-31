#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int dat) {
        data = dat;
        next = NULL;
    }
    Node() {}
};
struct Head {
    int len;
    Node* next;
    Head() {
        len = 0;
        next = NULL;
    }
};

bool insert(Head* h, int pos, int num) {
    if (pos > h->len + 1) {
        return 0;
    }
    Node* p = h->next;
    if (h->len == 0) {
        h->next = new Node(num);
        h->len++;
        return 1;
    }
    if (pos == 1) {
        Node* tmp = new Node(num);
        tmp->next = h->next;
        h->next = tmp;
        h->len++;
        return 1;
    }
    for (int i = 1; i < pos - 1; i++) {
        p = p->next;
    }
    Node* node = new Node(num);
    node->next = p->next;
    p->next = node;
    h->len++;

    return 1;
}

bool erase(Head* h, int pos) {
    if (pos > h->len) {
        return 0;
    }
    Node* p = h->next;
    if (pos == 1) {
        Node* p = h->next;
        h->next = p->next;
        h->len--;
        delete p;
        return 1;
    }
    for (int i = 1; i < pos - 1; i++) {
        p = p->next;
    }
    Node* q = p->next;
    p->next = q->next;
    delete q;
    h->len--;
    return 1;
}

void print(Head* h) {
    Node* p = h->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

bool swapNode(Head* h, int pa, int pb) {
    if (pa > pb)swap(pa, pb);
    if (pa<1 || pb > h->len) {
        return 0;
    }
    Node* tar1 = h->next;
    Node* tar2 = h->next;

    for (int i = 1; i < pa; i++) {
        tar1 = tar1->next;
    }
    for (int i = 1; i < pb; i++) {
        tar2 = tar2->next;
    }
    int val1 = tar1->data, val2 = tar2->data;
    // cout << val1 << " " << val2 << endl;
    erase(h, pa);
    // print(h);
    insert(h, pb, val1);
    // print(h);
    erase(h, pb - 1);
    // print(h);
    insert(h, pa, val2);
    return 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    Head* h = new Head();
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        insert(h, i + 1, tmp);
    }
    print(h);
    int pa, pb;
    for (int i = 0; i < 2; i++) {
        cin >> pa >> pb;
        if (swapNode(h,pa, pb)) {
            print(h);
        } else {
            cout << "error" << endl;
        }
    }



}