#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "shortest_path.hpp"

bool readGraphAndSourceNode(std::string &filePath, std::vector<std::vector<int>> &graph, int &sourceNode) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file " << filePath << std::endl;
        return false;
    }

    int nNodes = 0;
    file >> nNodes;
    if (nNodes <= 0) {
        std::cerr << "Number of nodes must be a positive number" << std::endl;
        return false;
    }

    int nEdges = 0;
    file >> nEdges;
    if (nEdges < nNodes - 1) {
        std::cerr << "Number of edges must be greater or equal to " << nNodes - 1 << std::endl;
        return false;
    }

    graph = std::vector<std::vector<int>>(nNodes, std::vector<int>(nNodes, 0));

    for (int i = 0; i < nEdges; ++i) {
        int node1 = 0;
        file >> node1;
        if (node1 < 0 || node1 >= nNodes) {
            std::cerr << "Node number must be in range [0, " << nNodes - 1 << "]" << std::endl;
            return false;
        }

        int node2 = 0;
        file >> node2;
        if (node2 < 0 || node2 >= nNodes) {
            std::cerr << "Node number must be in range [0, " << nNodes - 1 << "]" << std::endl;
            return false;
        }

        graph[node1][node2] = 1;
        graph[node2][node1] = 1;
    }

    file >> sourceNode;
    if (sourceNode < 0 || sourceNode >= nNodes) {
        std::cerr << "Source node number must be in range [0, " << nNodes - 1 << "]" << std::endl;
        return false;
    }

    file.close();

    return true;
}

void printDistances(std::vector<int> &distances) {
    for (int distance : distances) {
        std::cout << distance << std::endl;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " /path/to/graph.txt" << std::endl;
        return EXIT_FAILURE;
    }

    std::string filePath = argv[1];

    std::vector<std::vector<int>> graph;
    int sourceNode = 0;
    if (!readGraphAndSourceNode(filePath, graph, sourceNode)) {
        return EXIT_FAILURE;
    }

    std::vector<int> distances = ShortestPathFinder::findWithDijkstra(graph, sourceNode);
    // std::vector<int> distances = ShortestPathFinder::findWithBfs(graph, sourceNode);

    printDistances(distances);

    return EXIT_SUCCESS;
}
