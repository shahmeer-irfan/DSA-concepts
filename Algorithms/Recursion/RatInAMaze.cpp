#include <iostream>
#include <vector>

using namespace std;

class Maze
{
private:
    // Utility function to check if the next move is safe
    bool isSafe(int x, int y, int n, vector<vector<int>> &maze, vector<vector<int>> &visited)
    {
        // Check if (x, y) is inside the maze and is not visited or blocked
        if (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && visited[x][y] == 0)
        {
            return true;
        }
        return false;
    }

    // Recursive function to find all paths for the rat in the maze
    void ratInAMaze(vector<vector<int>> &maze, int n, int x, int y, string path, vector<vector<int>> &visited, vector<string> &ans)
    {
        // Base case: if the rat reaches the bottom-right corner, add the path to the answer
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1; // Mark the current cell as visited

        // Move Down (D)
        int newx = x + 1;
        int newy = y;
        if (isSafe(newx, newy, n, maze, visited))
        {
            path.push_back('D');
            ratInAMaze(maze, n, newx, newy, path, visited, ans);
            path.pop_back();
        }

        // Move Left (L)
        newx = x;
        newy = y - 1;
        if (isSafe(newx, newy, n, maze, visited))
        {
            path.push_back('L');
            ratInAMaze(maze, n, newx, newy, path, visited, ans);
            path.pop_back();
        }

        // Move Right (R)
        newx = x;
        newy = y + 1;
        if (isSafe(newx, newy, n, maze, visited))
        {
            path.push_back('R');
            ratInAMaze(maze, n, newx, newy, path, visited, ans);
            path.pop_back();
        }

        // Move Up (U)
        newx = x - 1;
        newy = y;
        if (isSafe(newx, newy, n, maze, visited))
        {
            path.push_back('U');
            ratInAMaze(maze, n, newx, newy, path, visited, ans);
            path.pop_back();
        }

        // Backtrack: unmark the current cell as visited
        visited[x][y] = 0;
    }

public:
    // Function to find the path in the maze
    vector<string> findPath(vector<vector<int>> &maze, int n)
    {
        vector<string> ans;
        if (maze[0][0] == 0) // If the source is blocked, return an empty vector
        {
            return ans;
        }

        string path;
        vector<vector<int>> visited(n, vector<int>(n, 0)); // Initialize visited array with zeros

        // Call the recursive function starting from the source (0, 0)
        ratInAMaze(maze, n, 0, 0, path, visited, ans);
        return ans; // Return the vector of paths
    }
};

int main()
{
    // Initialize the maze
    vector<vector<int>> maze = {
        {1, 0, 1, 1},
        {1, 1, 1, 0},
        {0, 1, 0, 1},
        {1, 1, 1, 1}};

    int n = maze.size(); // Size of the maze

    Maze obj;
    vector<string> result = obj.findPath(maze, n);

    // Print the result paths
    if (result.empty())
    {
        cout << "No path found" << endl;
    }
    else
    {
        cout << "Paths found: " << endl;
        for (auto path : result)
        {
            cout << path << endl;
        }
    }

    return 0;
}
