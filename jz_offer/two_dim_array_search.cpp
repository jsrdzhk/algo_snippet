#include "precompiled_headers.h"

class Solution {
   public:
    bool findNumberIn2DArray(std::vector<std::vector<int>>& matrix,
                             int target) {
        int matrix_height = matrix.size();
        if (matrix_height == 0) {
            return false;
        }
        int matrix_width = matrix[0].size();
        if (matrix_width == 0) {
            return false;
        }
        int up_right_dim_x = matrix_width - 1;
        int up_right_dim_y = 0;

        while (up_right_dim_x >= 0 && up_right_dim_y < matrix_height) {
            int current_num = matrix[up_right_dim_y][up_right_dim_x];
            if (current_num > target) {
                --up_right_dim_x;
            } else if (current_num == target) {
                return true;
            } else {
                ++up_right_dim_y;
            }
        }
        return false;
    }
};