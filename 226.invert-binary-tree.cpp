/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
    TreeNode *invertTree(TreeNode *root)
    {
        // 二叉树迭代前序遍历
        if (root == NULL)
            return root;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            if (node != NULL)
            {
                st.pop();
                if (node->right)
                    st.push(node->right); // 右
                if (node->left)
                    st.push(node->left); // 左
                st.push(node);           // 中
                st.push(NULL);
            }
            else
            {
                st.pop();
                node = st.top();
                st.pop();
                swap(node->left, node->right);
            }
        }
        return root;
        /*
        // 二叉树递归前序遍历
        if (root == NULL)
            return NULL; // return NULL 或 root一样
        // 对于最终结果来说并不重要，因为它并不会改变最后的遍历结果
        swap(root->left, root->right);// 中
        invertTree(root->left);// 左，这里其实已经发生了交换
        invertTree(root->right);// 右
        // 语句在这个递归函数中返回最后的遍历结果，
        // 即经过翻转后的树的根节点。
        return root;
        */
        /*
        invertTree(root->left);// 左，这里其实已经发生了交换
        swap(root->left, root->right);// 中
        invertTree(root->right);// 右
        这样中序遍历会出错，因为原先的左子树变成了现在的右子树，且已经完成了交换，再此交换会出错
        右子树跑到左面一直没有被处理
        正确写法：
        invertTree(root->left);
        swap(root->left, root->right);
        invertTree(root->left);
        */
    }
};
// @lc code=end
