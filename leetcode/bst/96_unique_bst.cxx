/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-12 16:13:27
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-12 16:48:46
 */

#include "precompiled_headers.h"
int numTrees(int n) {
    std::vector<int> dp{1, 1};
    for (auto i = 2; i <= n; ++i) {
        dp.push_back(0);
        for (auto j = 0; j < i; ++j) {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }
    return dp[n];
}