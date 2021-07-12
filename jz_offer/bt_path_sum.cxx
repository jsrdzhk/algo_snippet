/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-06-20 12:22:10
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-06-20 12:44:16
 */
#include "precompiled_headers.h"
class Solution
{
private:
    std::vector<std::vector<int>> res;
    int t;
    std::vector<int> cur;

public:
    std::vector<std::vector<int>> pathSum(TreeNode *root, int target)
    {
        t = target;
        pathSumImpl(root, 0);
        return res;
    }

    void pathSumImpl(TreeNode *root, int curSum)
    {
        if (!root)
        {
            return;
        }
        int v = root->val;
        cur.push_back(v);
        curSum += v;
        if (!root->left && !root->right)
        {
            if (curSum == t)
            {
                res.push_back(cur);
            }
        }
        else
        {
            pathSumImpl(root->left, curSum);
            pathSumImpl(root->right, curSum);
        }
        cur.pop_back();
        curSum -= v;
    }
};