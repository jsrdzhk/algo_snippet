/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-06-19 16:29:46
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-12 09:37:10
 */
#include "precompiled_headers.h"
class Solution
{
public:
    std::vector<int> levelOrder(TreeNode *root)
    {
        std::queue<TreeNode *> q;
        q.push(root);
        std::vector<int> res;
        while (!q.empty())
        {
            TreeNode *node = q.front();
            if (node)
            {
                res.push_back(node->val);
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            q.pop();
        }
        return res;
    }
};