#ifndef SHORTEST_PATH_HPP
#define SHORTEST_PATH_HPP

#include <vector>

class ShortestPathFinder {
public:
    static std::vector<int> findWithDijkstra(std::vector<std::vector<int>> &graph, int sourceNode);
    static std::vector<int> findWithBfs(std::vector<std::vector<int>> &graph, int sourceNode);
};

#endif
