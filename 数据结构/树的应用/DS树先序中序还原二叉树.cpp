#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

int findPosition(vector<char>& inorder, int start, int end, char value) {
    for (int i = start; i <= end; ++i) {
        if (inorder[i] == value) {
            return i;
        }
    }
    return -1; // This should never happen if the input is valid
}

TreeNode* buildTree(vector<char>& preorder, vector<char>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) {
        return NULL;
    }

    char rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);

    int inRoot = findPosition(inorder, inStart, inEnd, rootVal);
    int numsLeft = inRoot - inStart;

    root->left = buildTree(preorder, inorder, preStart + 1, preStart + numsLeft, inStart, inRoot - 1);
    root->right = buildTree(preorder, inorder, preStart + numsLeft + 1, preEnd, inRoot + 1, inEnd);

    return root;
}

int getTreeDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftDepth = getTreeDepth(root->left);
    int rightDepth = getTreeDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    int n;
    cin >> n;
    string preorderStr, inorderStr;
    cin >> preorderStr >> inorderStr;

    vector<char> preorder(preorderStr.begin(), preorderStr.end());
    vector<char> inorder(inorderStr.begin(), inorderStr.end());

    TreeNode* root = buildTree(preorder, inorder, 0, n - 1, 0, n - 1);

    int depth = getTreeDepth(root);
    cout << depth << endl;

    return 0;
}