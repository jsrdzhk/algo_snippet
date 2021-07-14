/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-13 11:31:22
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-13 14:10:47
 */
#include "precompiled_headers.h"
void backtrace(std::vector<std::vector<int>>& grid, int& res, int row, int col,
               int sum) {
    if (row == grid.size() - 1 && col == grid.size() - 1) {
        res = std::min(res, sum);
        return;
    }
    sum += grid[row][col];
    if (row + 1 < grid.size()) {
        backtrace(grid, res, row + 1, col, sum);
    }
    if (col + 1 < grid.size()) {
        backtrace(grid, res, row, col + 1, sum);
    }
    sum -= grid[row][col];
}

int minPathSum(std::vector<std::vector<int>>& grid) {
    int res = std::numeric_limits<std::size_t>::max();
    backtrace(grid, res, 0, 0, 0);
    return res;
}