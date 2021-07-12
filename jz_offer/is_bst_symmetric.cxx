/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-06-13 15:21:06
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-06-13 16:43:47
 */
#include "precompiled_headers.h"

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        std::vector<std::string> convertedBst = convertBstToVec(root);
        mirrorTree(root);
        std::vector<std::string> mirroredConvertedBst = convertBstToVec(root);
        return mirroredConvertedBst == convertedBst;
    }

private:
    std::vector<std::string> convertBstToVec(TreeNode *root)
    {
        std::vector<std::string> res;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *cur = q.front();
            if (cur)
            {
                res.push_back(std::to_string(cur->val));
                q.push(cur->left);
                q.push(cur->right);
            }
            else
            {
                res.push_back("n");
            }
            q.pop();
        }
        return res;
    }

    TreeNode *mirrorTree(TreeNode *root)
    {
        mirrorTreeImpl(root);
        return root;
    }

    void mirrorTreeImpl(TreeNode *node)
    {
        if (!node)
        {
            return;
        }
        std::swap(node->left, node->right);
        mirrorTreeImpl(node->left);
        mirrorTreeImpl(node->right);
    }
};