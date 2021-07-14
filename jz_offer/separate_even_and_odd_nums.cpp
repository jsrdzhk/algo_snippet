#include "precompiled_headers.h"

class Solution
{
public:
    std::vector<int> exchange(std::vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return nums;
        }
        int head = 0;
        int tail = nums.size() - 1;
        while (head < tail)
        {
            int head_num = nums[head];
            int tail_num = nums[tail];
            if (!is_odd_num(head_num))
            {
                if (is_odd_num(tail_num))
                {
                    std::swap(nums[head], nums[tail]);
                    ++head;
                }
                else
                {
                    --tail;
                }
            }
            else
            {
                ++head;
            }
        }
        return nums;
    }

private:
    bool is_odd_num(int num)
    {
        return num % 2;
    }
};