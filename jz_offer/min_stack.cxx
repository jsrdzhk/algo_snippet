/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-06-19 12:45:52
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-06-19 12:51:46
 */
#include "precompiled_headers.h"

class MinStack
{
private:
    std::stack<int> mainStack;
    std::stack<int> helpStack;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        if (helpStack.empty() || helpStack.top() >= x)
        {
            helpStack.push(x);
        }
        mainStack.push(x);
    }

    void pop()
    {
        int topNum = mainStack.top();
        if (helpStack.top() == topNum)
        {
            helpStack.pop();
        }
        mainStack.pop();
    }

    int top()
    {
        return mainStack.top();
    }

    int min()
    {
        return helpStack.top();
    }
};