/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-06-19 16:36:42
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-06-19 17:11:05
 */
#include "precompiled_headers.h"

class Solution
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        std::queue<TreeNode *> q;
        q.push(root);
        std::vector<std::vector<int>> res;
        while (true)
        {
            std::vector<int> v;
            std::vector<TreeNode *> tmp;
            while (!q.empty())
            {
                TreeNode *node = q.front();
                if (node)
                {
                    v.push_back(node->val);
                    if (node->left)
                    {
                        tmp.push_back(node->left);
                    }
                    if (node->right)
                    {
                        tmp.push_back(node->right);
                    }
                }
                q.pop();
            }
            if (!v.empty())
            {
                res.push_back(v);
            }
            if (tmp.empty())
            {
                break;
            }
            for (auto node : tmp)
            {
                q.push(node);
            }
        }
        return res;
    }
};