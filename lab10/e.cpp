#include <iostream>
#include <vector>
using namespace std;

// Function to check if all three elements can be added together without causing an explosion
string canAdd(const vector<vector<int>>& adj, int a, int b, int c) {
    // Check all pairwise combinations
    if (adj[a][b] && adj[b][c] && adj[a][c]) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    // Read the adjacency matrix
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
        }
    }

    // Process the queries
    for (int i = 0; i < q; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << canAdd(adj, a - 1, b - 1, c - 1) << endl;
    }

    return 0;
}
