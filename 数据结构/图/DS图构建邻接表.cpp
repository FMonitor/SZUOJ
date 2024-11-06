#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int index; 
    ListNode* next;
    ListNode(int idx) : index(idx), next(nullptr) {}
};

struct Vertex {
    char info;
    ListNode* next;
    Vertex(int id) : info(id), next(nullptr) {}
    Vertex() : next(nullptr) {}
};


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        Vertex* vertex = new Vertex[n];
        map<char, int> mp;
        for (int i = 0; i < n; i++) {
            char ch;
            cin >> ch;
            mp[ch] = i;
            vertex[i].info = ch;
        }
        for (int i = 0; i < k; i++) {
            char a, b;
            cin >> a >> b;
            int x = mp[a], y = mp[b];
            ListNode* node = new ListNode(y);
            ListNode* p = vertex[x].next;
            while (p && p->next) p = p->next;
            if (!p) vertex[x].next = node;
            else p->next = node;
        }
        for (int i = 0; i < n; i++) {
            cout << i << " " << vertex[i].info << "-";
            ListNode* node = vertex[i].next;
            while (node) {
                cout << mp[vertex[node->index].info] << "-";
                node = node->next;
            }
            cout << "^" << endl;
        }
    }
    return 0;
}