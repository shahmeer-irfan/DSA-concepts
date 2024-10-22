//23k-0832
#include <iostream>
#include <vector>
using namespace std;

class RatInMaze
{
private:
    // Helper function to check if the move is valid
    bool isSafe(int x, int y, vector<vector<int>> &maze, vector<vector<int>> &visited, int n)
    {
        return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && visited[x][y] == 0);
    }

    // Backtracking function to find all paths
    void findPaths(int x, int y, vector<vector<int>> &maze, int n, vector<string> &result, string path, vector<vector<int>> &visited)
    {
        // If destination is reached, store the current path
        if (x == n - 1 && y == n - 1)
        {
            result.push_back(path);
            return;
        }

        // Mark the current cell as visited
        visited[x][y] = 1;

        // Move Down (D)
        if (isSafe(x + 1, y, maze, visited, n))
        {
            findPaths(x + 1, y, maze, n, result, path + 'D', visited);
        }

        // Move Left (L)
        if (isSafe(x, y - 1, maze, visited, n))
        {
            findPaths(x, y - 1, maze, n, result, path + 'L', visited);
        }

        // Move Right (R)
        if (isSafe(x, y + 1, maze, visited, n))
        {
            findPaths(x, y + 1, maze, n, result, path + 'R', visited);
        }

        // Move Up (U)
        if (isSafe(x - 1, y, maze, visited, n))
        {
            findPaths(x - 1, y, maze, n, result, path + 'U', visited);
        }

        // Backtrack: Unmark the current cell as visited
        visited[x][y] = 0;
    }

public:
    // Function to find all paths from (0, 0) to (n-1, n-1)
    vector<string> solveMaze(vector<vector<int>> &maze, int n)
    {
        vector<string> result;                             // To store all possible paths
        vector<vector<int>> visited(n, vector<int>(n, 0)); // To track visited cells

        // If the starting point is blocked, return empty result
        if (maze[0][0] == 0)
        {
            return result;
        }

        // Start finding paths from (0, 0)
        findPaths(0, 0, maze, n, result, "", visited);

        return result;
    }
};

int main()
{
    // Example maze
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    int n = maze.size();
    RatInMaze rat;

    // Find all paths
    vector<string> paths = rat.solveMaze(maze, n);

    // Output all found paths
    if (paths.empty())
    {
        cout << "No path found!" << endl;
    }
    else
    {
        cout << "Possible paths are: " << endl;
        for (const string &path : paths)
        {
            cout << path << endl;
        }
    }

    return 0;
}
