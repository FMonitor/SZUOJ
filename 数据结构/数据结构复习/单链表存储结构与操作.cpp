#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};


struct Head {
    Node* first;
    int len = 0;
};

bool insert(Head* mylist, Node* node, int pos) {
    if (pos<1 || pos>mylist->len + 1) {
        cout << "error" << endl;
        return 0;
    }
    if (mylist->len == 0) {
        mylist->first = new Node();
    }
    Node* p = mylist->first;
    for (int i = 0; i < pos-1; i++) {
        p = p->next;
    }
    node->next = p->next;
    p->next = node;
    mylist->len++;
    return 1;
}

bool remove(Head* mylist, int pos) {
    if (pos > mylist->len || pos < 1) {
        cout << "error" << endl;
        return 0;
    }
    Node* p = mylist->first;
    for (int i = 1; i < pos; i++) {
        p = p->next;
    }
    Node* q = p->next;
    p->next = q->next;
    mylist->len--;
    delete q;
    return 1;
}

bool query(Head* mylist, int pos) {
    if (pos > mylist->len || pos < 1) {
        cout << "error" << endl;
        return 0;
    }
    Node* p = mylist->first;
    for (int i = 1; i <=pos; i++) {
        p = p->next;
    }
    cout << p->data << endl;
    return 1;
}

void print(Head* mylist) {
    cout << mylist->len<<" ";
    Node* p = new Node();
    p = mylist->first;
    p = p->next;
    while (p->next != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << p->data <<" "<< endl;
}

int main() {
#ifndef ONLINE_JUDGE    
    freopen("in.txt", "r", stdin);
#endif
    
    int n;
    cin >> n;
    Head* mylist = new Head();
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        Node* nextNode = new Node();
        nextNode->data = tmp;
        insert(mylist, nextNode, i);
    }
    print(mylist);
    int pos, data;
    for (int i = 0; i < 2; i++) {
        cin >> pos >> data;
        Node* nextNode = new Node();
        nextNode->data = data;
        if (insert(mylist, nextNode, pos))
            print(mylist);
    }
    for (int i = 0; i < 2; i++) {
        cin >> pos;
        if (remove(mylist, pos))
            print(mylist);
    }
    for (int i = 0; i < 2; i++) {
        cin >> pos;
        query(mylist, pos);
    }
    return 0;
}