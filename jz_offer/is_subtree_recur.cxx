/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-06-12 17:21:58
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-06-12 17:40:00
 */
#include "precompiled_headers.h"
class Solution
{
public:
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if (!B || !A)
        {
            return false;
        }
        return isSubTree(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

private:
    bool isSubTree(TreeNode *a, TreeNode *b)
    {
        if (!b)
        {
            return true;
        }
        if (!a || a->val != b->val)
        {
            return false;
        }
        return isSubTree(a->left, b->left) && isSubTree(a->right, b->right);
    }
};