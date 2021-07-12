/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-06-20 14:13:38
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-06-20 15:06:23
 */
#include "precompiled_headers.h"

class Codec
{
private:
    const std::string nullStr = "null";

public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode *root)
    {
        std::queue<TreeNode *> q;
        q.push(root);
        std::vector<std::string> res;
        while (!q.empty())
        {
            TreeNode *node = q.front();
            if (!node)
            {
                res.push_back(nullStr);
            }
            else
            {
                res.push_back(std::to_string(node->val));
                if (node->left || node->right)
                {
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            q.pop();
        }
        return convertVecToStr(res);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(std::string data)
    {
        std::vector<std::string> converted = convertStrToVec(data);
        for (int i = 0; i < converted.size(); ++i)
        {
            auto s = converted[i];
            if (s == nullStr)
            {
            }
        }
    }

private:
    std::string convertVecToStr(const std::vector<std::string> &src)
    {
        std::string res = "[";
        for (const auto &s : src)
        {
            res += s;
            res += ",";
        }
        res = res.substr(0, res.size() - 1);
        res += "]";
        return res;
    }

    std::vector<std::string> convertStrToVec(const std::string &src)
    {
        std::vector<std::string> res;
        std::string sub = src.substr(1, src.size() - 2);
        std::stringstream ss(sub);
        while (ss.good())
        {
            std::string tmp;
            std::getline(ss, tmp, ',');
            res.push_back(tmp);
        }
        return res;
    }
};