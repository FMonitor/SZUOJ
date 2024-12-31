#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* lc;
    Node* rc;
    int dat;
    Node() {}
    Node(int dat) {
        this->dat = dat;
        lc = NULL;
        rc = NULL;
    }
};

int arr[1000];
int n, m;

void buildTree(Node*root, int index) {
    while (1) {
        if (root->dat > arr[index]) {
            if (root->lc != NULL) {
                root = root->lc;
                cout << "left ";
            } else {
                root->lc = new Node(arr[index]);
                cout <<root->dat <<" insert left: " << arr[index] <<" ";
                break;
            }
        } else {
            if (root->rc != NULL) {
                root = root->rc;
                cout << "right ";
            } else {
                root->rc = new Node(arr[index]);
                cout <<root->dat <<" insert right: " << arr[index] <<" ";
                break;
            }
        }
    }
}

Node* findClosest(Node* root) {
    while (root->rc != NULL) {
        root = root->rc;
    }
    return root;
}

// Node* search(Node* root, int num) {
//     if (root == NULL)return NULL;
//     if (root->dat > num) {
//         return search(root->lc, num);
//     } else if(root->dat<num){
//         return search(root->rc, num);
//     } else {
//         return root;
//     }
//     return NULL;
// }

void rmNode(Node*& root, int num) {
    if (root == NULL) return;
    if (root->dat > num) {
        rmNode(root->lc, num);
    } else if (root->dat < num) {
        rmNode(root->rc, num);
    } else {
        if (root->lc == NULL) {
            Node* tmp = root->rc;
            delete root;
            root = tmp;
        } else if (root->rc == NULL) {
            Node* tmp = root->rc;
            delete root;
            root = tmp;
        } else {
            Node* closest = findClosest(root->lc);
            root->dat = closest->dat;
            rmNode(root->lc, closest->dat);
        }
    }
}

void levelOrder(Node* root) {
    if (root == NULL) return;
    levelOrder(root->lc);
    cout << root->dat<<" ";
    levelOrder(root->rc);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Node* root = new Node(arr[0]);
        for (int i = 1; i < n; i++) {
            buildTree(root, i);
            cout << endl;
        }
        levelOrder(root);
        cin >> m;
        for (int i = 0; i < m; i++) {
            int rm;
            cin >> rm;
            rmNode(root, rm);
            levelOrder(root);
            cout << endl;
        }
    }
    return 0;
}