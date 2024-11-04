#include<bits/stdc++.h> 
using namespace std;
int B;
int N;
class Node {
public:
    char data;
    Node** child;
    Node() {
        child = new Node * [B];
    }
};
class BNode {
public:
    char data;
    BNode* firstchild;
    BNode* next;
};
class Tree {
public:
    Node* root;
    string str;
    int pos;
    Tree(string s) {
        str.assign(s);
        pos = 0;
        root = creat();

    }

    Node* creat() {
        if (str[pos] == '0') {
            pos++;
            return NULL;
        }

        Node* p = new Node;
        p->data = str[pos];
        pos++;
        for (int i = 0;i < B;i++) {
            p->child[i] = creat();
        }
        return p;
    }
    BNode* change(Node* T) {
        BNode* p = NULL;
        if (T) {
            p = new BNode;
            p->data = T->data;
            int cnt = 0;
            while (!T->child[cnt] && cnt < B) cnt++;
            if (cnt == B) p->firstchild = change(NULL);
            else p->firstchild = change(T->child[cnt]);
            if (p->firstchild) {
                BNode* q = p->firstchild;

                for (int i = cnt + 1;i < B;i++) {
                    q->next = change(T->child[i]);
                    if (q->next) q = q->next;
                }
            }
        }
        return p;
    }
};

class BTree {
public:
    BNode* root;

    BTree(Tree T) {
        root = T.change(T.root);
    }
};

void preOrder(BNode* p, string s) {
    if (!p->firstchild && !p->next) {
        for (int i = 0;i < s.length();i++) {
            if (i) cout << " ";
            cout << s[i];
        }
        cout << endl;
    }
    if (p->firstchild) preOrder(p->firstchild, s + '0');
    if (p->next) preOrder(p->next, s + '1');
}

int main() {
    cin >> N >> B;
    BNode* p;
    for (int i = 0;i < N;i++) {
        string s;
        char op;
        while (cin >> op) {
            s += op;
            if (getchar() == '\n') break;
        }
        Tree mytree(s);
        BTree t(mytree);
        if (i == 0) {
            p = t.root;
        } else {
            BNode* q = p;
            while (q->next) q = q->next;
            q->next = t.root;
        }
    }
    preOrder(p, "");

    return 0;
}