#include <algorithm>
#include <forward_list>
#include <unordered_set>
#include <vector>

class Solution {
   public:
    int findRepeatNumber(std::vector<int> &nums) {
        std::unordered_set<int> numSet;
        for (auto &&num : nums) {
            if (numSet.count(num)) {
                return num;
            } else {
                numSet.insert(num);
            }
        }
        // sort(nums);
        // for (auto i = 0; i < nums.size(); ++i) {
        //     if (nums[i] != i) {
        //         return i;
        //     }
        // }
        return 0;
    }

   private:
    template <class ForwardIt>
    void quickSortImpl(ForwardIt bg, ForwardIt end) {
        int distance = std::distance(bg, end);
        if (distance < 1) {
            return;
        }
        auto pivot = *std::next(bg, distance / 2);
        ForwardIt middle1 = std::partition(
            bg, end, [=](const auto &elem) { return elem < pivot; });
        ForwardIt middle2 = std::partition(
            middle1, end, [=](const auto &elem) { return elem == pivot; });
        quickSortImpl(bg, middle1);
        quickSortImpl(middle2, end);
    }
    void sort(std::vector<int> &nums) {
        std::forward_list<int> unordered_nums(nums.begin(), nums.end());
        quickSortImpl(unordered_nums.begin(), unordered_nums.end());
        nums = std::vector<int>(unordered_nums.begin(), unordered_nums.end());
    }
};