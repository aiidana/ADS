#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int shortestPath(const vector<vector<int>>& graph, int start, int end) {
    int n = graph.size();
    vector<int> dist(n, -1); 
    queue<int> q;

    
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // Check adjacent vertices
        for (int i = 0; i < n; ++i) {
            if (graph[current][i] && dist[i] == -1) {
                q.push(i);
                dist[i] = dist[current] + 1; // Update distance
            }
        }
    }

    return dist[end];
}

int main() {
    int n;
    cin >> n;

    // Input the adjacency matrix
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    int start, end;
    cin >> start >> end;

    // Find and output the shortest path
    int shortest = shortestPath(graph, start - 1, end - 1);
    cout << shortest << endl;

    return 0;
}
