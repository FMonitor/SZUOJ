#include<bits/stdc++.h>
using namespace std;
class Node {
private:
    int data;
    Node* next;
public:
    Node() {
        data = 0;
        next = nullptr;
    }
    Node(int dat) {
        data = dat;
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
    void newList(int arr[], int len) {
        length = len;
        Node* tmp = new Node(arr[0]);
        head->next = tmp;
        Node* it = tmp;
        for (int i = 1; i < len; i++) {
            tmp = new Node(arr[i]);
            it->next = tmp;
            it = it->next;
        }
        it->next = nullptr;
        print();
    }
    void insert(int dat, int pos) {
        if (pos<=0||pos > length+1) {
            cout << "error" << endl;
            return;
        }
        pos -= 1;
        Node* tmp = new Node(dat);
        Node* it = head;
        while (pos--) {
            it = it->next;
        }
        tmp->next = it->next;
        it->next = tmp;
        length++;
        print();
    }
    void erase(int pos) {
        if (pos<=0||pos > length) {
            cout << "error" << endl;
            return;
        }
        pos--;
        Node* it = head;
        while (pos--) {
            it = it->next;
        }
        Node* tmp = it->next;
        it->next = tmp->next;
        delete tmp;
        length--;
        print();
    }
    void query(int pos) {
        if (pos <= 0 || pos > length) {
            cout << "error" << endl;
            return;
        }
        Node* it = head;
        while (pos--) {
            it = it->next;
        }
        cout << it->data << endl;
    }
    void print() {
        if (length==0) {
            return;
        }
        Node* it = head->next;
        while (it != nullptr) {
            cout << it->data << " ";
            it = it->next;
        }
        cout << endl;
    }
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int len;
    cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }
    List ls;
    ls.newList(arr, len);
    int pos, dat;
    cin >> pos >> dat;
    ls.insert(dat, pos);
    cin >> pos >> dat;
    ls.insert(dat, pos);

    cin >> pos;
    ls.erase(pos);
    cin >> pos;
    ls.erase(pos);

    cin >> pos;
    ls.query(pos);
    cin >> pos;
    ls.query(pos);
    return 0;
}