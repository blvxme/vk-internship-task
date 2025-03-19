#include "shortest_path.hpp"

#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <unordered_set>
#include <utility>

constexpr int INF = std::numeric_limits<int>::max();

std::vector<int> ShortestPathFinder::findWithDijkstra(std::vector<std::vector<int>> &graph, int sourceNode) {
    int n = graph.size();

    std::vector<int> distances(n, INF);

    std::unordered_set<int> visited;

    using pii = std::pair<int, int>;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> minHeap;
    minHeap.push({0, sourceNode});

    while (!minHeap.empty()) {
        int currentNode = minHeap.top().second;
        int currentDistance = minHeap.top().first;
        minHeap.pop();

        visited.insert(currentNode);
        distances[currentNode] = std::min(distances[currentNode], currentDistance);

        for (int nextNode = 0; nextNode < n; ++nextNode) {
            if (graph[currentNode][nextNode] && !visited.contains(nextNode)) {
                int nextDistance = graph[currentNode][nextNode];
                minHeap.push({currentDistance + nextDistance, nextNode});
            }
        }
    }

    return distances;
}

std::vector<int> ShortestPathFinder::findWithBfs(std::vector<std::vector<int>> &graph, int sourceNode) {
    int n = graph.size();

    std::vector<int> distances(n, INF);
    distances[sourceNode] = 0;

    std::queue<int> queue;
    queue.push(sourceNode);

    while (!queue.empty()) {
        int currentNode = queue.front();
        queue.pop();

        for (int nextNode = 0; nextNode < n; ++nextNode) {
            if (graph[currentNode][nextNode] == 0) {
                continue;
            }

            if (distances[nextNode] == INF) {
                distances[nextNode] = 1 + distances[currentNode];

                queue.push(nextNode);
            }
        }
    }

    return distances;
}
