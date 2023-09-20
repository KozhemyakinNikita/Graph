//
//  main.cpp
//  Lab_10
//
//  Created by Nik Kozhemyakin on 18.05.2023.
//


#include "Graph.hpp"

int main() {
    int numVertices;
    std::cout << "Введите количество вершин: ";
    std::cin >> numVertices;
    Graph graph(numVertices);

    int numEdges;
    std::cout << "Введите количество ребер: ";
    std::cin >> numEdges;

    std::cout << "Введите ребра в формате 'source destination weight':" << '\n';
    for (int i = 0; i < numEdges; ++i) {
        int source, destination, weight;
        std::cin >> source >> destination >> weight;
        graph.addEdge(source, destination, weight);
    }

    int startVertex;
    std::cout << "Введите начальную вершину: ";
    std::cin >> startVertex;

    graph.bellmanFord(startVertex);
    graph.BFS(startVertex);

    return 0;
}


/*
 1 graph
 4 5
0 1 5
0 2 5
1 3 2
2 3 -1
2 1 -4
 
 2 graph
 5 8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 1 1
3 2 5
4 3 -3
 
 3 graph
 7 12
0 1 8
0 2 5
1 3 1
1 6 8
2 1 2
2 4 1
2 5 3
3 4 2
4 3 1
5 0 5
5 6 2
6 0 4
 
 4 graph
 6 9
0 1 7
0 2 9
1 3 -1
1 4 -2
2 1 -3
2 4 2
3 4 1
3 5 3
4 5 3
*/




/*
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
        this -> numVertices = numVertices;
    }

    void addEdge(int source, int destination, int weight) {
        edges.push_back({source, destination, weight});
    }

    void bellmanFord(int startVertex) {
        std::vector<int> distance(numVertices, std::numeric_limits<int>::max());
        distance[startVertex] = 0;

        for (int i = 0; i < numVertices - 1; ++i) {
            for (int j = 0; j < edges.size(); ++j) {
                int start = edges[j].source;
                int end = edges[j].destination;
                int wt = edges[j].weight;

                if (distance[start] != std::numeric_limits<int>::max() && distance[start] + wt < distance[end]) {
                    distance[end] = distance[start] + wt;
                }
            }
        }

        // Проверяем наличие отрицательных циклов
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i].source;
            int v = edges[i].destination;
            int w = edges[i].weight;

            if (distance[u] != std::numeric_limits<int>::max() && distance[u] + w < distance[v]) {
                std::cout << "Граф содержит отрицательный цикл!" << std::endl;
                return;
            }
        }

        // Выводим кратчайшие пути
        std::cout << "Кратчайшие пути от вершины " << startVertex << ":" << std::endl;
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Вершина " << i << ": " << distance[i] << '\n';
        }
    }

    void BFS(int startVertex) {
        std::vector<bool> visited(numVertices, false);
        std::vector<int> queue;

        visited[startVertex] = true;
        queue.push_back(startVertex);

        std::cout << "Результат обхода в ширину (BFS): ";
        while (!queue.empty()) {
            int currentVertex = queue.front();
            queue.erase(queue.begin());

            std::cout << currentVertex << " ";

            for (int i = 0; i < edges.size(); ++i) {
                const Edge& edge = edges[i];
                if (edge.source == currentVertex && !visited[edge.destination]) {
                    visited[edge.destination] = true;
                    queue.push_back(edge.destination);
                }
            }

        }

        std::cout << std::endl;
    }
};

int main() {
    int numVertices;
    std::cout << "Введите количество вершин: ";
    std::cin >> numVertices;
    Graph graph(numVertices);

    int numEdges;
    std::cout << "Введите количество ребер: ";
    std::cin >> numEdges;

    std::cout << "Введите ребра в формате 'source destination weight':" << std::endl;
    for (int i = 0; i < numEdges; ++i) {
        int source, destination, weight;
//        std::cout << "Ребро " << i+1 << ": ";
        std::cin >> source >> destination >> weight;
        graph.addEdge(source, destination, weight);
    }
//    graph.addEdge(0, 1, 5);
//    graph.addEdge(0, 2, 5);
//    graph.addEdge(1, 2, 3);
//    graph.addEdge(2, 3, -1);
//    graph.addEdge(2, 1, -4);
    int startVertex;
    std::cout << "Введите начальную вершину: ";
    std::cin >> startVertex;

    graph.bellmanFord(startVertex);
    graph.BFS(startVertex);

    return 0;
}

*/
