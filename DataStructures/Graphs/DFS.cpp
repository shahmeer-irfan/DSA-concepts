#include <iostream>
#include <vector>
using namespace std;

// DEPTH FIRST SEARCH

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
    }

    // Helper function for DFS traversal
    void DFSfun(vector<bool> &visited, int s)
    {
        visited[s] = true; // Marking current vertex as visited
        cout << s << " ";

        for (int i : adjList[s])
        {
            if (!visited[i]) // Only visit unvisited neighbors
            {
                DFSfun(visited, i);
            }
        }
    }

    // DFS Function to handle disconnected graphs
    void DFS()
    {
        vector<bool> visited(v, false);
        cout << "DFS Traversal of the Graph:" << endl;

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                DFSfun(visited, i);
                cout << endl; // Separate components
            }
        }
    }
};

int main()
{
    Graph undirectedGraph(false, 5); // Create an undirected graph with 5 vertices

    undirectedGraph.addEdge(0, 1);
    undirectedGraph.addEdge(0, 4);
    undirectedGraph.addEdge(1, 2);
    undirectedGraph.addEdge(2, 3);
    undirectedGraph.addEdge(2, 4);

    undirectedGraph.display();

    // Perform DFS directly using the class method
    undirectedGraph.DFS(); // Perform DFS traversal

    return 0;
}
