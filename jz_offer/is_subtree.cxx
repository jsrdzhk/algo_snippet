/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-06-12 08:10:33
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-06-12 17:14:56
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
        std::string aStr = charVecToString(convertTreeToVec(A));
        std::string bStr = charVecToString(convertTreeToVec(B));
        auto res = aStr.find(bStr);
        return res != std::string::npos;
    }

private:
    std::vector<std::string> convertTreeToVec(TreeNode *root)
    {
        std::vector<std::string> treeNodeVec;
        std::queue<TreeNode *> treeNodeQueue;
        treeNodeQueue.push(root);
        while (!treeNodeQueue.empty())
        {
            TreeNode *cur = treeNodeQueue.front();
            if (!cur)
            {
                treeNodeVec.push_back("n");
            }
            else
            {
                treeNodeVec.push_back(std::to_string(cur->val));
                treeNodeQueue.push(cur->left);
                treeNodeQueue.push(cur->right);
            }
            treeNodeQueue.pop();
        }
        return treeNodeVec;
    }

    std::string charVecToString(const std::vector<std::string> &charVec)
    {
        const char *delm = ",";
        std::ostringstream imploid;
        std::copy(charVec.begin(), charVec.end(), std::ostream_iterator<std::string>(imploid, delm));
        std::string res = imploid.str();
        return res.substr(0, res.size() - 1);
    }
};