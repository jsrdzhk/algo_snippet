/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-06-13 15:13:29
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-06-13 15:17:16
 */
#include "precompiled_headers.h"

class Solution
{
public:
    TreeNode *mirrorTree(TreeNode *root)
    {
        mirrorTreeImpl(root);
        return root;
    }

private:
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