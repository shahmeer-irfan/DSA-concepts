#include <iostream>
#include <cstring> // For memset

using namespace std;

#define MAX_NODES 100 // Maximum number of nodes

// Graph class for BFS traversal
class Graph
{
    int vertices;                        // Number of vertices
    int adjMatrix[MAX_NODES][MAX_NODES]; // Adjacency matrix

public:
    // Constructor
    Graph(int V)
    {
        vertices = V;
        memset(adjMatrix, 0, sizeof(adjMatrix)); // Initialize matrix with 0
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v)
    {
        adjMatrix[u][v] = 1; // Set the connection in the adjacency matrix
        adjMatrix[v][u] = 1; // For undirected graph
    }

    // BFS function
    void BFS(int start)
    {
        int visited[MAX_NODES] = {0}; // Visited array to mark visited nodes
        int queue[MAX_NODES];         // Manual queue
        int front = 0, rear = 0;      // Front and rear pointers

        // Start BFS
        visited[start] = 1;    // Mark the starting node as visited
        queue[rear++] = start; // Enqueue the starting node

        cout << "BFS starting from vertex " << start << ": ";

        while (front != rear)
        {                                 // While queue is not empty
            int current = queue[front++]; // Dequeue the front node
            cout << current << " ";

            // Check all neighbors
            for (int i = 0; i < vertices; i++)
            {
                if (adjMatrix[current][i] == 1 && !visited[i])
                {                      // If there’s a connection and not visited
                    visited[i] = 1;    // Mark as visited
                    queue[rear++] = i; // Enqueue the neighbor
                }
            }
        }
        cout << endl;
    }
};



int main()
{
    Graph g(6); // Create a graph with 6 vertices (0 to 5)

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    // Perform BFS starting from vertex 0
    g.BFS(0);

    return 0;
}
