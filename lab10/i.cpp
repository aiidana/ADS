#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// Function to perform topological sorting
bool topologicalSort(int n, const vector<vector<int>>& adj, vector<int>& inDegree, vector<int>& order) {
    queue<int> q;
    unordered_set<int> visited;

    // Enqueue vertices with in-degree 0
    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        visited.insert(u);

        // Update in-degree of adjacent vertices
        for (int v : adj[u]) {
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return visited.size() == n;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Create adjacency list representation of the graph
    vector<vector<int>> adj(n + 1);
    vector<int> inDegree(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
    }

    // Perform topological sorting
    vector<int> order;
    bool possible = topologicalSort(n, adj, inDegree, order);

    // Output the result
    if (possible) {
        cout << "Possible" << endl;
        for (int vertex : order) {
            cout << vertex << " ";
        }
        cout << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}
