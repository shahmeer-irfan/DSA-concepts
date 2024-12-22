#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BREADTH FIRST SEARCH

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

    // BFS Function inside the class
    void BFS(int source) //BFS(int source, vector<bool> &visited)
    {
        queue<int> q;
        vector<bool> visited(v, false);

        visited[source] = true;
        q.push(source);

        cout << "BFS traversal starting from vertex " << source << ": ";
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            cout << front << " "; //we can also make answer array and push elements in it and then traverse answer

            for (int x : adjList[front])
            {
                if (!visited[x])
                {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        cout << endl;
    }

    // void BFS_Disconnected()  //for disconnected graph
    // {
    //     vector<bool> visited(v, false); // Track visited vertices
    //     for (int i = 0; i < v; ++i)
    //     {
    //         if (!visited[i]) // If vertex 'i' has not been visited
    //         {
    //             BFS(i, visited); // Perform BFS for this component
    //         }
    //     }
    // }
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

    // Perform BFS directly using the class method
    undirectedGraph.BFS(0); // Start BFS from vertex 0

    return 0;
}
