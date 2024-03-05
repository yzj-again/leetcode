/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    // 二叉树迭代遍历
    // 问题：无法同时解决访问节点（遍历节点）和处理节点（将元素放进结果集）不一致的情况。
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        if (root != NULL)
            st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top(); // 中间节点让出位置
            if (node != NULL)
            {
                st.pop();// 当前中间节点先出栈，先处理左右孩子
                if (node->right)
                    st.push(node->right); // 放入右节点
                st.push(node);            // 再次放入中间节点
                st.push(NULL);            // 标记，中间节点访问过，但还没没有被处理
                if (node->left)
                    st.push(node->left); // 放入左节点
            }
            else
            {             // 只有遇到NULL才将结果放入结果集
                st.pop(); // 处理标记的中间节点
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }

        return result;
    }

    // 二叉树递归中序遍历
    /*
    void traversal(TreeNode *cur, vector<int> &vec)
    {
        if (cur == NULL)
            return;
        traversal(cur->left, vec);
        vec.push_back(cur->val);
        traversal(cur->right, vec);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traversal(root, result);
        return result;
    }
    */
};
// @lc code=end
