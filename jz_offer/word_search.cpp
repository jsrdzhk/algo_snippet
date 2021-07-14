#include "precompiled_headers.h"

class Solution {
   public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        std::size_t height = board.size();
        std::size_t width = board[0].size();
        std::size_t board_word_num = height * width;
        if (board_word_num < word.size()) {
            return false;
        }
        for (std::size_t i = 0; i < height; ++i) {
            for (std::size_t j = 0; j < width; ++j) {
                if (board[i][j] == word[0]) {
                    std::vector<std::vector<bool>> visited(
                        height, std::vector<bool>(width, false));
                    visited[i][j] = true;
                    if (find_word(board, i, j, word, 1, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

   private:
    bool find_word(const std::vector<std::vector<char>>& board, std::size_t i,
                   std::size_t j, const std::string& word, std::size_t word_idx,
                   std::vector<std::vector<bool>>& visited) {
        if (word_idx == word.size()) {
            return true;
        }
        char ch = word[word_idx];
        if (j > 0) {
            char left_ch = board[i][j - 1];
            if (!visited[i][j - 1] && left_ch == ch) {
                visited[i][j - 1] = true;
                if (find_word(board, i, j - 1, word, word_idx + 1, visited)) {
                    return true;
                } else {
                    visited[i][j - 1] = false;
                }
            }
        }
        if (i > 0) {
            char up_ch = board[i - 1][j];
            if (!visited[i - 1][j] && up_ch == ch) {
                visited[i - 1][j] = true;
                if (find_word(board, i - 1, j, word, word_idx + 1, visited)) {
                    return true;
                } else {
                    visited[i - 1][j] = false;
                }
            }
        }
        if (j < board[0].size() - 1) {
            char right_ch = board[i][j + 1];
            if (!visited[i][j + 1] && right_ch == ch) {
                visited[i][j + 1] = true;
                if (find_word(board, i, j + 1, word, word_idx + 1, visited)) {
                    return true;
                } else {
                    visited[i][j + 1] = false;
                }
            }
        }
        if (i < board.size() - 1) {
            char down_ch = board[i + 1][j];
            if (!visited[i + 1][j] && down_ch == ch) {
                visited[i + 1][j] = true;
                if (find_word(board, i + 1, j, word, word_idx + 1, visited)) {
                    return true;
                } else {
                    visited[i + 1][j] = false;
                }
            }
        }
        return false;
    }
};