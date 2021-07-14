/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-07-12 17:59:59
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-07-13 07:52:24
 */
#include "precompiled_headers.h"

void traverse(std::vector<std::vector<int>>& graph, int idx, int target,
              std::vector<std::vector<int>>& res, std::vector<int>& seq) {
    if (idx == target) {
        seq.push_back(idx);
        res.push_back(seq);
        seq.pop_back();
    }
    auto& g = graph[idx];
    for (auto num : g) {
        seq.push_back(idx);
        traverse(graph, num, target, res, seq);
        seq.pop_back();
    }
}

std::vector<std::vector<int>> allPathsSourceTarget(
    std::vector<std::vector<int>>& graph) {
    std::vector<int> seq;
    std::vector<std::vector<int>> res;
    traverse(graph, 0, graph.size() - 1, res, seq);
    return res;
}