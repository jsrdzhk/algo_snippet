/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-13 07:53:09
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-13 07:59:36
 */
#include "precompiled_headers.h"

void permuteImpl(std::vector<int>& nums, int s, int e,
                 std::vector<std::vector<int>>& res, std::vector<int>& seq) {
    if (seq.size() == nums.size()) {
        res.push_back(seq);
        return;
    }
    for (auto i = s; i < e; ++i) {
        seq.push_back(nums[i]);
        std::swap(nums[s], nums[i]);
        permuteImpl(nums, s + 1, e, res, seq);
        std::swap(nums[s], nums[i]);
        seq.pop_back();
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    std::vector<int> seq;
    permuteImpl(nums, 0, nums.size(), res, seq);
    return res;
}