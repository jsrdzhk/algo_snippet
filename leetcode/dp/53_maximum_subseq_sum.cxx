/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-13 10:55:30
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-13 11:06:34
 */
#include "precompiled_headers.h"

int maxSubArray(std::vector<int>& nums) {
    int res = std::numeric_limits<int>::min();
    std::vector<std::vector<int>> dp(nums.size() - 1,
                                     std::vector<int>(nums.size(), res));
    dp[0][0] = nums[0];
    res = std::max(dp[0][0], res);
    for (auto i = 1; i < nums.size(); ++i) {
        for (auto j = 0; j <= i; ++j) {
            if (j == i) {
                dp[j][i] = nums[i];
            } else {
                dp[j][i] = dp[j][i - 1] + nums[i];
            }
            res = std::max(dp[j][i], res);
        }
    }
    return res;
}