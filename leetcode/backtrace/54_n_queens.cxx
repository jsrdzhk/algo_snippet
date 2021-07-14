/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-13 08:17:19
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-13 08:17:39
 */
#include "precompiled_headers.h"

bool isValid(std::vector<std::string>& board, int rowNum, int colNum) {
    auto n = board.size();
    for (auto i = 0; i < n; ++i) {
        if (board[i][colNum] == 'Q') {
            return false;
        }
    }
    for (auto i = rowNum - 1, j = colNum + 1; i >= 0 && j < board.size();
         --i, ++j) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    for (auto i = rowNum - 1, j = colNum - 1; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}

void backtrace(std::vector<std::vector<std::string>>& res,
               std::vector<std::string>& board, int row) {
    if (row == board.size()) {
        res.push_back(board);
        return;
    }
    for (auto c = 0; c < board.size(); ++c) {
        if (!isValid(board, row, c)) {
            continue;
        }
        board[row][c] = 'Q';
        backtrace(res, board, row + 1);
        board[row][c] = '.';
    }
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> board(n, std::string(n, '.'));
    backtrace(res, board, 0);
    return res;
}