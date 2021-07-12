/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-06-20 09:26:15
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-06-20 12:19:51
 */
#include "precompiled_headers.h"

class Solution
{
public:
    bool verifyPostorder(std::vector<int> &postorder)
    {
        if (postorder.size() <= 1)
        {
            return true;
        }
        return verifyImpl(postorder, 0, postorder.size() - 1);
    }

    bool verifyImpl(const std::vector<int> &postorder, int s, int e)
    {
        if (e - s <= 1)
        {
            return true;
        }
        int root = postorder[e];
        int p = s;
        while (postorder[p] < root)
        {
            ++p;
        }
        int m = p;
        while (postorder[p] > root)
        {
            ++p;
        }
        return p == e && verifyImpl(postorder, s, m - 1) && verifyImpl(postorder, m, e - 1);
    }
};