/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-06-19 17:36:56
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-06-19 17:37:30
 */
#include "precompiled_headers.h"
class Solution
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        int lineNum = 0;
        std::vector<std::vector<int>> res;
        std::queue<TreeNode *> q;
        q.push(root);
        while (true)
        {
            std::queue<TreeNode *> tmpQ;
            std::vector<int> v;
            while (!q.empty())
            {
                TreeNode *node = q.front();
                if (node)
                {
                    v.push_back(node->val);
                    if (node->left)
                    {
                        tmpQ.push(node->left);
                    }
                    if (node->right)
                    {
                        tmpQ.push(node->right);
                    }
                }
                q.pop();
            }
            if (!v.empty())
            {
                if (lineNum % 2)
                {
                    std::reverse(v.begin(), v.end());
                }
                res.push_back(v);
            }
            if (tmpQ.empty())
            {
                break;
            }
            else
            {
                std::swap(q, tmpQ);
            }
            ++lineNum;
        }
        return res;
    }
};