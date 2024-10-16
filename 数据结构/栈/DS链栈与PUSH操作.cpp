#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int dat, Node* nxt) {
        data = dat;
        next = nxt;
    }
};
class SqStack {
    Node* head;
    int length;
public:
    static bool InitStack(SqStack& S) {
        S.head = nullptr;
        S.length = 0;
        return true;
    }
    static bool Push(SqStack& S, int e) {
        Node* tmp = new Node(e, nullptr);
        Node* p = S.head;
        for (int i = 0; i < S.length; i++) {
            p = p->next;
        }
        p->next = tmp;
        S.length++;
        return true;
    }
    static int GetTop(SqStack& S) {
        Node* tmp = S.head;
        for (int i = 0; i < S.length; i++) {
            tmp = tmp->next;
        }
        return tmp->data;
    }
};

int main() {
    int t;
    cin >> t;
    SqStack S;
    SqStack::InitStack(S);
    while (t--) {
        int e;
        cin >> e;
        SqStack::Push(S, e);
        cout << SqStack::GetTop(S);
    }
    return 0;
}
