#include <iostream>
#include <vector>

using namespace std;

class Graph
{
    int vertices;
    vector<vector<int>> adjMatrix;

    public:
    Graph(int v): vertices(v)
    {
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int start, int end)  
    {
        adjMatrix[start][end] = 1;  //it will be the case in both graphs for directed and undirected
        adjMatrix[end][start] =1; //for undirected graph
    }

    void display()
    {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < vertices; ++i)
        {
            for (int j = 0; j < vertices; ++j)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

};

int main()
{
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(3, 4);

    graph.display();

    return 0;
}