/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-06-19 15:07:47
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-06-19 16:28:09
 */
#include "precompiled_headers.h"
class Solution
{
public:
    bool validateStackSequences(std::vector<int> &pushed, std::vector<int> &popped)
    {
        auto len = pushed.size();
        std::size_t popIdx = 0;
        std::size_t pushIdx = 0;
        std::stack<int> helpStack;
        while (popIdx < len)
        {
            auto curStackTop = popped[popIdx];
            while (true)
            {
                if (pushIdx >= len)
                {
                    return false;
                }
                auto curPushNum = pushed[pushIdx];
                helpStack.push(curPushNum);
                ++pushIdx;
                if (curPushNum == curStackTop)
                {
                    break;
                }
            }
            while (!helpStack.empty())
            {
                auto curPushTop = helpStack.top();
                if (popped[popIdx] == curPushTop)
                {
                    ++popIdx;
                    helpStack.pop();
                }
                else
                {
                    break;
                }
            }
        }
        return true;
    }
};