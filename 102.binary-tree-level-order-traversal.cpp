/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> queue;
        int queueSize = 0;
        // 代码随想录是放在第一层while里
        vector<vector<int>> result;
        if (root != NULL)
            queue.push(root);
        while (!queue.empty())
        {
            // int size = que.size();
            queueSize = queue.size();
            vector<int> vec; // 存放一层的结果
            // TreeNode *node; // 代码随想录是放里面
            // 无论是将node放在循环外部还是循环内部，对于性能来说并没有本质的区别。
            // 编译器会对代码进行优化，使其在底层执行时具有相似的性能。
            // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
            while (queueSize--)
            {
                TreeNode *node = queue.front();
                queue.pop();
                vec.push_back(node->val);
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};
// @lc code=end
