#include "precompiled_headers.h"

class Solution {
   public:
    int movingCount(int m, int n, int k) {
        int count = 1;
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        visited[0][0] = true;
        std::queue<std::pair<int, int>> q;
        q.emplace(0, 0);
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            auto right_p = std::make_pair(x, y + 1);
            if (is_point_valid(visited, right_p, m, n, k)) {
                q.push(right_p);
                ++count;
            }
            auto down_p = std::make_pair(x + 1, y);
            if (is_point_valid(visited, down_p, m, n, k)) {
                q.push(down_p);
                ++count;
            }
        }
        return count;
    }

   private:
    bool is_point_valid(std::vector<std::vector<bool>>& visited,
                        const std::pair<int, int>& point, int m, int n, int k) {
        if (point.first >= 0 && point.second < m && point.second >= 0 &&
            point.second < n && calc_pos_sum(point.first, point.second) <= k &&
            !visited[point.first][point.second]) {
            visited[point.first][point.second] = true;
            return true;
        }
        return false;
    }
    int calc_pos_sum(int m, int n) { return calc_bit_sum(n) + calc_bit_sum(n); }
    int calc_bit_sum(int num) {
        int res = 0;
        for (; num; num /= 10) {
            res += num % 10;
        }
        return res;
    }
};