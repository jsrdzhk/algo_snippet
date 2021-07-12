/*
 * @title: todo
 * @author: Rodney Cheung
 * @date: 2021-06-13 16:48:41
 * @last_author: Rodney Cheung
 * @last_edit_time: 2021-06-19 12:43:19
 */
#include "precompiled_headers.h"

class Solution
{
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
    {
        std::vector<int> res;
        auto height = matrix.size();
        if (height > 0)
        {
            auto width = matrix[0].size();
            Point topLeft(0, 0);
            Point topRight(0, width - 1);
            Point downLeft(height - 1, 0);
            Point downRight(height - 1, width - 1);
            printRound(matrix, res, topLeft, topRight, downLeft, downRight);
        }
        return res;
    }

private:
    struct Point
    {
        int x;
        int y;
        Point(int xPoint, int yPoint) : x(xPoint), y(yPoint) {}
    };

    void printRound(const std::vector<std::vector<int>> &matrix, std::vector<int> &res, Point topLeft, Point topRight, Point downLeft, Point downRight)
    {
        if (topLeft.y > topRight.y)
        {
            return;
        }
        else if (topLeft.y == topLeft.y)
        {
            res.push_back(matrix[topLeft.x][topLeft.y]);
        }
        else
        {
            printImpl(matrix, res, topLeft, topRight, downLeft, downRight);
            Point newTopLeft(topLeft.x + 1, topLeft.y + 1);
            Point newTopRight(topRight.x + 1, topRight.y - 1);
            Point newDownLeft(downLeft.x - 1, downLeft.y + 1);
            Point newDownRight(topRight.x - 1, topRight.y - 1);
            printRound(matrix, res, newTopLeft, newTopRight, newDownLeft, newDownRight);
        }
    }

    void printImpl(const std::vector<std::vector<int>> &matrix, std::vector<int> &res, Point &topLeft, Point &topRight, Point &downLeft, Point &downRight)
    {
        printRight(matrix, res, topLeft, topRight);
        printDown(matrix, res, topRight, downRight);
        printLeft(matrix, res, downRight, downLeft);
        printUp(matrix, res, downLeft, topLeft);
    }
    void printRight(const std::vector<std::vector<int>> &matrix, std::vector<int> &res,
                    const Point &topLeft, const Point &topRight)
    {
        for (auto s = topLeft.y; s < topRight.y; ++s)
        {
            res.push_back(matrix[topLeft.x][s]);
        }
    }

    void printDown(const std::vector<std::vector<int>> &matrix, std::vector<int> &res,
                   const Point &topRight, const Point &downRight)
    {
        for (auto s = topRight.x; s < downRight.x; ++s)
        {
            res.push_back(matrix[s][downRight.y]);
        }
    }

    void printLeft(const std::vector<std::vector<int>> &matrix, std::vector<int> &res,
                   const Point &downRight, const Point &downLeft)
    {
        for (auto s = downRight.y; s > downLeft.y; --s)
        {
            res.push_back(matrix[downRight.x][s]);
        }
    }
    void printUp(const std::vector<std::vector<int>> &matrix, std::vector<int> &res,
                 const Point &downLeft, const Point &topLeft)
    {
        for (auto s = downLeft.x; s > topLeft.x; --s)
        {
            res.push_back(matrix[s][downLeft.y]);
        }
    }
};