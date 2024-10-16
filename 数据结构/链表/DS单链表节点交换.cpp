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
    static int LL_merge(List* La, List* Lb) {
        Node* ita = La->head->next;
        Node* itb = Lb->head->next;
        int indexa = 1;
        int indexb = 1;
        while(indexa<=La->length || indexb<=Lb->length) {
            if (ita == nullptr || itb == nullptr) {
                break;
            }
            if (ita->data > itb->data) {
                La->insert(itb->data, indexa);
                indexa++;
                indexb++;
                itb = itb->next;
            } else {
                Lb->insert(ita->data, indexb);
                indexb++;
                indexa++;
                ita = ita->next;
            }
        }
        if (La->length > Lb->length)
            La->print();
        else
            Lb->print();
        return 1;
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
        // print();
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
    List la, lb;
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }
    la.newList(arr, len);
    cin >> len;
    int arr2[len];
    for (int i = 0; i < len; i++) {
        cin >> arr2[i];
    }
    lb.newList(arr2, len);
    List::LL_merge(&la, &lb);
    return 0;
}
