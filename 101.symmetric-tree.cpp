/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool compare(TreeNode *left, TreeNode *right)
    {
        // 首先排除空节点的情况
        if (left == NULL && right != NULL)
            return false;
        else if (left != NULL && right == NULL)
            return false;
        else if (left == NULL && right == NULL)
            return true;
        // 排除空节点后再比较数值
        else if (left->val != right->val)
            return false;
        // 此时就是：左右节点都不为空，且数值相同的情况
        // 此时再进行递归
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool isSame = outside && inside;
        // 也是左右中的顺序、中序，但此时不是严格的中序遍历
        // 只是逻辑上进行了这个顺序
        return isSame;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return compare(root->left, root->right);
    }
};
// @lc code=end
