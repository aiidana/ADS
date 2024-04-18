#include <iostream>
#include <vector>
using namespace std;

// DFS function to visit all connected land cells
void dfs(vector<vector<char>>& grid, int row, int col) {
    int n = grid.size();
    int m = grid[0].size();

    // Check if the current cell is within bounds and is land
    if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] != '1') {
        return;
    }

    // Mark the current cell as visited
    grid[row][col] = '0';

    // Visit adjacent land cells
    dfs(grid, row + 1, col); // Down
    dfs(grid, row - 1, col); // Up
    dfs(grid, row, col + 1); // Right
    dfs(grid, row, col - 1); // Left
}

// Function to count the number of islands
int countIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int islands = 0;

    // Iterate through each cell in the grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // If the cell is land and hasn't been visited yet, perform DFS
            if (grid[i][j] == '1') {
                islands++;
                dfs(grid, i, j);
            }
        }
    }

    return islands;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Input the grid
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    // Count and output the number of islands
    cout << countIslands(grid) << endl;

    return 0;
}
