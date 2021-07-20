/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-20 15:30:20
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-20 16:14:45
 */
#include "precompiled_headers.h"

std::vector<int> searchRange(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    std::vector<int> res{-1, -1};
    if (nums.empty()) {
        return res;
    }
    while (left < right) {
        int middle = left + (right - left) / 2;
        //当middle位置的数大于目标数时，说明目标数在该数的左侧;
        //当等于目标数时，说明该数的左侧（不包括该数）也可能存在跟目标数相同的其他数，继续向左二分查找
        if (nums[middle] >= target) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    //当下标处数据非法时，说明没有找到目标数，直接返回
    if (left >= nums.size()) {
        return res;
    }
    if (nums[left] == target) {
        res[0] = left;
    } else {
        return res;
    }
    right = nums.size();
    while (left < right) {
        int middle = left + (right - left) / 2;
        if (nums[middle] > target) {
            right = middle;
        } else {
            //当middle位置的数等于目标数时，说明该数右侧的数字也有可能等于目标数，继续向右二分查找。
            left = middle + 1;
        }
    }
    //此时右侧的数必然在目标数右边，所以目标数的右侧下标需要减一
    res[1] = left - 1;
    return res;
}