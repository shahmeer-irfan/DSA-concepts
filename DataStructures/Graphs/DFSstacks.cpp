#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
    int v;                       // Number of vertices
    vector<vector<int>> adjList; // Adjacency list to store the graph
    int direction;               // 1 for directed, 0 for undirected

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
            adjList[v].push_back(u);
    }

    // Function to perform iterative DFS
    void DFS(int start)
    {
        vector<bool> visited(v, false); // Keep track of visited nodes
        stack<int> s;                   // Stack for DFS

        s.push(start); // Push the starting node

        cout << "DFS traversal starting from vertex " << start << ": ";

        while (!s.empty())
        {
            int current = s.top(); // Get the top element
            s.pop();

            if (!visited[current])
            {
                visited[current] = true; // Mark as visited
                cout << current << " ";

                // Push all unvisited neighbors onto the stack
                for (int neighbor : adjList[current])
                {
                    if (!visited[neighbor])
                    {
                        s.push(neighbor);
                    }
                }
            }
        }
        cout << endl;
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

    undirectedGraph.DFS(0); // Perform DFS starting from vertex 0

    return 0;
}
