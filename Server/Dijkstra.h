#include <limits.h>
#include <stdio.h>
#include <iostream>

// Numero de vertices en el grago
#define V 9

// funcion paara encontrar el valor minimo de distancia, desde
// el conjunto de vértices aún no incluidos en el árbol de ruta más corta
int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index = min;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// funcion para imprimir la distancia de la matriz
std::string printSolution(int dist[], int n)
{

    std::string string;
    for (int i = 0 ; i < 9 ; ++i)
    {
        string += "node " + std::to_string(i) + " --- Distance from node 0 --> " + std::to_string(dist[i]) + "\n";
    }
    return string;
}

// funcion que implementa el algoritmo de dijkstra en el grafo
std::string dijkstra(int graph[V][V], int src)
{
    int dist[V];

    bool sptSet[V];


    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;


    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {

        int u = minDistance(dist, sptSet);


        sptSet[u] = true;


        for (int v = 0; v < V; v++)

            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }


    std::string  output = printSolution(dist, V);
    return output;
}
