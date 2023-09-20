//
//  Graph.hpp
//  Lab_10
//
//  Created by Nik Kozhemyakin on 18.05.2023.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <limits>

struct Edge {
    int source;
    int destination;
    int weight;
};

class Graph {
    int numVertices;
    std::vector<Edge> edges;

public:
    Graph(int numVertices) {
        this->numVertices = numVertices;
    }

    void addEdge(int source, int destination, int weight);

    void bellmanFord(int startVertex);

    void BFS(int startVertex);
};

#endif /* Graph_hpp */
