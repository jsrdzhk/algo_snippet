/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-20 15:25:26
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-20 15:28:41
 */
#include "precompiled_headers.h"

int search(std::vector<int>& nums, int target) {
    int start = 0, end = nums.size();
    while (start < end) {
        int middle = start + (end - start) / 2;
        if (nums[middle] > target) {
            end = middle;
        } else if (nums[middle] == target) {
            return middle;
        } else {
            start = middle + 1;
        }
    }
    return -1;
}