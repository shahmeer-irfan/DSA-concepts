#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    int v;                       // Number of vertices
    vector<vector<int>> adjList; // Adjacency list to store the graph
    int direction;               // 1 is directed, 0 is undirected

public:
    Graph(bool d, int v) : direction(d)
    {
        adjList.resize(v); // Resize the adjacency list to have 'v' vertices
        this->v = v;
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v); // Add the directed edge from u to v
        if (!direction)          // If undirected, also add the reverse edge from v to u
        {
            adjList[v].push_back(u);
        }
    }

    // Function to display the graph
    void display()
    {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < v; ++i)
        {
            cout << i << ": ";
            for (int j : adjList[i]) // Iterate through neighbors of vertex i
            {
                cout << j << " -> ";
            }
            cout << endl;
        }
    //using normal loop
    //     for (int i = 0; i < v; ++i) // Iterate through all vertices
    //     {
    //         cout << i << ": "; // Print the current vertex
    //         // Iterate through the neighbors of vertex 'i' using a normal for loop
    //         for (int j = 0; j < adjList[i].size(); ++j) // Loop over the neighbors
    //         {
    //             cout << adjList[i][j] << " -> "; // Print each neighbor
    //         }
    //         cout << endl; // Print a newline after each vertex's neighbors
    //     }
    // }
    
}
};


int main()
{
    // Example for Directed Graph
    cout << "Directed Graph:" << endl;
    Graph directedGraph(true, 6); // Create a directed graph with 5 vertices

    directedGraph.addEdge(0, 1);
    directedGraph.addEdge(0, 4);
    directedGraph.addEdge(1, 2);
    directedGraph.addEdge(5, 3);
    directedGraph.addEdge(2, 5);

    directedGraph.display(); // Display the directed graph

    // Example for Undirected Graph
    cout << "\nUndirected Graph:" << endl;
    Graph undirectedGraph(false, 5); // Create an undirected graph with 5 vertices

    undirectedGraph.addEdge(0, 1);
    undirectedGraph.addEdge(0, 4);
    undirectedGraph.addEdge(1, 2);
    undirectedGraph.addEdge(2, 3);
    undirectedGraph.addEdge(2, 4);

    undirectedGraph.display(); // Display the undirected graph

    return 0;
}
