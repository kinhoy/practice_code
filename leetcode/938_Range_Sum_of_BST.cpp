#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int rangeSumBST(TreeNode *root, int L, int R)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->val > R)
    {
        return rangeSumBST(root->left, L, R);
    }
    else if (root->val < L)
    {
        return rangeSumBST(root->right, L, R);
    }
    else
    {
        return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
}