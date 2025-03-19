#include <gtest/gtest.h>
#include <vector>

#include "shortest_path.hpp"

TEST(BfsTest, BasicTest) {
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0}
    };

    std::vector<int> actual = ShortestPathFinder::findWithBfs(graph, 4);
    std::vector<int> expected = {1, 2, 3, 3, 0};

    EXPECT_EQ(actual, expected);
}

TEST(BfsTest, BasicPlusOneAdditionalEdgeTest) {
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {1, 1, 0, 0, 0}
    };

    std::vector<int> actual = ShortestPathFinder::findWithBfs(graph, 4);
    std::vector<int> expected = {1, 1, 2, 2, 0};

    EXPECT_EQ(actual, expected);
}

TEST(BfsTest, CyclicGraphTest) {
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0}
    };

    std::vector<int> actual = ShortestPathFinder::findWithBfs(graph, 0);
    std::vector<int> expected = {0, 1, 2, 3, 4, 3, 2, 1};

    EXPECT_EQ(actual, expected);
}
