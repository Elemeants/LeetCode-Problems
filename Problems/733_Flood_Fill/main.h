//
// 733. Flood Fill
//
#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <stack>
#include <set>
#include <cmath>

using vector2D = std::vector<std::vector<int>>;

class Cell
{
    int _x, _y;
    vector2D &ref;

    std::pair<int, int> getImageDimensions() const
    {
        return std::make_pair(ref.size(), ref[0].size());
    }

public:
    Cell(vector2D &ref, const int x, const int y) : _x(x), _y(y), ref(ref) {}

    const int &getValue() const { return ref[_x][_y]; }
    void setValue(const int v) { ref[_x][_y] = v; }
    vector2D &getRef() const { return ref; }

    int x() const { return _x; }
    int y() const { return _y; }

    bool valid() const
    {
        const auto dimensions = getImageDimensions();
        return (_x >= 0 && _x < dimensions.first) && (_y >= 0 && _y < dimensions.second);
    }
};

Cell operator+(const Cell &left, const std::pair<int, int> &right)
{
    return Cell(left.getRef(), left.x() + right.first, left.y() + right.second);
}

class Solution
{
    using listCoords2D = std::vector<Cell>;

public:
    vector2D floodFill(const vector2D &image, int sr, int sc, int color)
    {
        const int &initialPixelValue = image[sr][sc];
        const std::pair<int, int> dimensions = getImageDimensions(image);
        if (dimensions.first == 1 && dimensions.second == 1)
        {
            return vector2D{{initialPixelValue}};
        }

        vector2D output = image;
        if (initialPixelValue == color)
        {
            return output;
        }

        Cell startingNode{output, sr, sc};

        iterateOverNodes(startingNode, initialPixelValue, color);

        return output;
    }

    void iterateOverNodes(Cell &parent, const int &original, const int &color)
    {
        parent.setValue(color);
        auto adjacentNodes = searchForSameNeighborsNodes(parent, original);
        for (auto &node : adjacentNodes)
        {
            iterateOverNodes(node, original, color);
        }
    }

    std::pair<int, int> getImageDimensions(const vector2D &image)
    {
        return std::make_pair(image.size(), image[0].size());
    }

    listCoords2D searchForSameNeighborsNodes(const Cell &cell, const int &original)
    {
        const std::vector<std::pair<int, int>> relativeCoords = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        listCoords2D foundedCoords = {};
        for (const std::pair<int, int> &rCoord : relativeCoords)
        {
            Cell rCell = cell + rCoord;
            if (isCoordValid(rCell, original))
            {
                foundedCoords.push_back(rCell);
            }
        }

        return foundedCoords;
    }

    bool isCoordValid(const Cell &cell, const int &expected_value)
    {
        return cell.valid() && cell.getValue() == expected_value;
    }
};
