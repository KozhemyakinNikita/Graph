//
//  Graph.cpp
//  Lab_10
//
//  Created by Nik Kozhemyakin on 18.05.2023.
//

#include "Graph.hpp"

void Graph::addEdge(int source, int destination, int weight) {
    edges.push_back({source, destination, weight});
}


void Graph::bellmanFord(int startVertex) {
    std::vector<int> distance(numVertices, std::numeric_limits<int>::max());
    std::vector<int> parent(numVertices, -1);
    distance[startVertex] = 0;
    
    for (int i = 0; i < numVertices - 1; ++i) {
        for (int j = 0; j < edges.size(); ++j) {
            int src = edges[j].source;
            int dst = edges[j].destination;
            int wt = edges[j].weight;
            
            if (distance[src] != std::numeric_limits<int>::max() && distance[src] + wt < distance[dst]) {
                distance[dst] = distance[src] + wt;
                parent[dst] = src;
            }
        }
    }
    
    // Проверяем наличие отрицательных циклов
    for (int i = 0; i < edges.size(); ++i) {
        int start = edges[i].source;
        int end = edges[i].destination;
        int wt = edges[i].weight;
        
        if (distance[start] != std::numeric_limits<int>::max() && distance[start] + wt < distance[end]) {
            std::cout << "Граф содержит отрицательный цикл!" << '\n';
            return;
        }
    }
    
    // Выводим кратчайшие пути
    std::cout << "Кратчайшие пути от вершины " << startVertex << ":" << '\n';
    for (int i = 0; i < numVertices; ++i) {
        if (distance[i] != std::numeric_limits<int>::max()) {
            std::cout << startVertex << " -> " << i << " = " << distance[i] << '\n';
        } else {
            std::cout << startVertex << " -> " << i << " = INF" << '\n';
        }
    }

    
     /*
    for (int i = 0; i < numVertices; ++i) {
        if (distance[i] != std::numeric_limits<int>::max()) {
            std::cout << startVertex << " -> " << i << " = " << distance[i] << std::endl;
            std::cout << "Путь: ";
            int currentVertex = i;
            std::vector<int> path;
            while (currentVertex != -1) {
                path.insert(path.begin(), currentVertex);
                currentVertex = parent[currentVertex];
            }
            for (int j = 0; j < path.size(); ++j) {
                std::cout << path[j];
                if (j != path.size() - 1) {
                    std::cout << " -> ";
                }
            }
            std::cout << std::endl;
        } else {
            std::cout << startVertex << " -> " << i << " = INF" << std::endl;
            std::cout << "Путь: Нет пути" << std::endl;
        }
    }
     
    */
    

    // Выводим самый краткий путь из заданной точки до последней
    std::cout << "Самый короткий путь из " << startVertex << " до последней вершины: ";
    int currentVertex = numVertices - 1;
    std::vector<int> shortestPath;
    while (currentVertex != -1) {
        shortestPath.insert(shortestPath.begin(), currentVertex);
        currentVertex = parent[currentVertex];
    }
    
    for (int i = 0; i < shortestPath.size(); ++i) {
        std::cout << shortestPath[i];
        if (i != shortestPath.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << '\n';
}


void Graph::BFS(int startVertex) {
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
    
    std::cout <<'\n';
}
