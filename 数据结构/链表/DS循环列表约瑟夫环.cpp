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
        // print();
    }
    void erase(int pos) {
        if (pos <= 0 || pos > length) {
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
    }
    void count(int k, int s) {
        Node* it = head;
        while (it->next != nullptr) {
            it = it->next;
        }
        it->next = head->next;
        s--;
        while (s--) {
            it = it->next;
        }
        int cnt = 1;
        while (length > 0) {
            if (cnt == k) {
                cout << it->next->data << " ";
                Node* toDelete = it->next;
                it->next = toDelete->next;
                delete toDelete;
                length--;
                cnt = 1;
            } else {
                it = it->next;
                cnt++;
            }
        }
        cout << endl;
    }
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, k, s;
        cin >> n >> k >> s;
        int arr[n];
        for (int i = 0; i < n; i++) arr[i] = i + 1;
        List Ls;
        Ls.newList(arr, n);
        Ls.count(k, s);
    }
    return 0;
}
