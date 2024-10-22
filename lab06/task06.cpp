// 23k-0832
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to check if the move is within bounds and a valid tree
bool isSafe(int x, int y, const vector<vector<char>> &field, vector<vector<bool>> &visited, int n, int m)
{
    return (x >= 0 && x < n && y >= 0 && y < m && field[x][y] == 'T' && !visited[x][y]);
}

// Perform DFS to explore all connected trees
int dfs(int x, int y, const vector<vector<char>> &field, vector<vector<bool>> &visited, int n, int m)
{
    // Movement in 4 possible directions: Up, Down, Left, Right
    int rowOffsets[] = {-1, 1, 0, 0};
    int colOffsets[] = {0, 0, -1, 1};

    // Mark the current cell as visited
    visited[x][y] = true;

    int forestSize = 1;

    // Explore all four directions
    for (int i = 0; i < 4; i++)
    {
        int newX = x + rowOffsets[i];
        int newY = y + colOffsets[i];

        // If the move is valid, continue the DFS
        if (isSafe(newX, newY, field, visited, n, m))
        {
            forestSize += dfs(newX, newY, field, visited, n, m);
        }
    }

    return forestSize;
}

int largestForest(const vector<vector<char>> &field)
{
    int n = field.size();
    int m = field[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int maxForestSize = 0;

    // Iterate through every cell in the grid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // If we find an unvisited tree, perform DFS to find the size of the connected forest
            if (field[i][j] == 'T' && !visited[i][j])
            {
                int forestSize = dfs(i, j, field, visited, n, m);
                maxForestSize = max(maxForestSize, forestSize);
            }
        }
    }

    return maxForestSize;
}

int main()
{
    // Example field (2D grid)
    vector<vector<char>> field = {
        {'T', 'T', 'T', 'W', 'W'},
        {'T', 'W', 'W', 'T', 'T'},
        {'T', 'W', 'W', 'T', 'T'},
        {'T', 'W', 'T', 'T', 'T'},
        {'W', 'W', 'T', 'T', 'T'}};

    int largestForestSize = largestForest(field);
    cout << "The size of the largest forest is: " << largestForestSize << endl;

    return 0;
}
