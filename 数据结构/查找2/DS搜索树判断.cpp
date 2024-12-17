#include<bits/stdc++.h>
using namespace std;

typedef struct TNode* Ptrtree;
typedef struct TNode {
    int Data;
    Ptrtree left;
    Ptrtree right;
}tnode;

int N;
vector<int>v1, v2, v3, v4;

//建立二叉搜索树
Ptrtree insert(Ptrtree root, int x) {
    //插入完第一个后  根节点也就固定了 
    if (root == NULL) {//将插入的操作视为 查找的时的操作,插入的地点视为 查找失败的地点 在查找失败的地点 插入一个结点
        root = (Ptrtree)malloc(sizeof(struct TNode));
        root->left = NULL;
        root->right = NULL;
        root->Data = x;
        return root;
    }
    if (root->Data > x) {
        root->left = insert(root->left, x);
    } else if (root->Data <= x) {
        root->right = insert(root->right, x);
    } else {
        return NULL;
    }
    return root;
}
Ptrtree creatTree(int A[], Ptrtree root) {
    root = NULL;
    int i;
    for (i = 0; i < N; i++) {
        root = insert(root, A[i]);
    }
    return root;
}
void  Preorder1(Ptrtree root) {
    if (root != NULL) {
        int temp = root->Data;
        v1.push_back(temp);
        Preorder1(root->left);
        Preorder1(root->right);
    }
}
void Postorder1(Ptrtree root) {
    if (root != NULL) {
        Postorder1(root->left);
        Postorder1(root->right);
        int temp = root->Data;
        v2.push_back(temp);
    }
}

void  Preorder2(Ptrtree root) {
    if (root != NULL) {
        int temp = root->Data;
        v3.push_back(temp);
        Preorder2(root->right);
        Preorder2(root->left);
    }
}

void Postorder2(Ptrtree root) {
    if (root != NULL) {
        Postorder2(root->right);
        Postorder2(root->left);
        int temp = root->Data;
        v4.push_back(temp);
    }
}

int  judgment(int a[], vector<int>& v) {
    int flag = 0;

    for (int i = 0; i < N; i++) {
        if (a[i] != v[i]) {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        return 1;
    else
        return 0;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int a[1000];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    Ptrtree root;
    root = creatTree(a, root);
    Preorder1(root);
    int flag1 = judgment(a, v1); //判断二叉搜索树的前序是否正确 
    if (flag1 == 1) {
        cout << "YES" << endl;
        Postorder1(root);
        for (int i = 0; i < v2.size(); i++) {
            if (i != N - 1) {
                cout << v2[i] << ' ';
            } else {
                cout << v2[i];
            }
        }
    } else {
        //比较是否是镜像的二叉树
        Preorder2(root);
        int flag2 = judgment(a, v3);
        if (flag2 == 1) {
            cout << "YES" << endl;
            Postorder1(root);
            for (int i = 0; i < N; i++) {
                if (i != N - 1)
                    cout << v4[i] << ' ';
                else
                    cout << v4[i];
            }
        } else {
            cout << "NO";
        }
    }
}