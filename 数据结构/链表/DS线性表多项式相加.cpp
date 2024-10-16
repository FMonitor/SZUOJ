#include<bits/stdc++.h>
using namespace std;
class Node {
private:
    int num;
    int mul;
    Node* next;
public:
    Node() {
        num = 0;
        next = nullptr;
    }
    Node(int dat) {
        num = dat;
        next = nullptr;
    }
    friend class List;
};
class List {
private:
    Node* head;
    int length;
public:
    List() {
        length = 0;
        head = new Node();
    }
    List(int n) {
        length = n;
        head = new Node();
        Node* it = head;
        for (int i = 0; i < n; i++) {
            Node* tmp = new Node();
            cin >> tmp->num;
            cin >> tmp->mul;
            it->next = tmp;
            it = it->next;
        }
    }
    void insert(int n, int m) {//尾插
        Node* it = head;
        while (it->next != nullptr) {
            it = it->next;
        }
        Node* tmp = new Node();
        tmp->num = n;
        tmp->mul = m;
        it->next = tmp;
        length++;
    }
    void print() {
        Node* it = head->next;
        while (it != nullptr) {
            if (it->num != 0) { // 系数不为0
                // 如果系数或指数是负数，用小括号括起来
                if (it->num < 0) {
                    cout << "(" << it->num << ")";
                } else {
                    cout << it->num;
                }
                if (it->mul != 0) {
                    if (it->mul < 0) {
                        cout << "x^(" << it->mul << ")";
                    } else {
                        cout << "x^" << it->mul;
                    }
                }
                if (it->next != nullptr && it->next->num != 0) {
                    cout << " + ";
                }
            }
            it = it->next;
        }
        cout << endl;
    }
};
int main() {
    int t;
    while (t--) {
        int n;
        cin >> n;
        List l(n);
        l.print();
    }
    return 0;
}