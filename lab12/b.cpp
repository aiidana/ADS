#include <iostream>
#include <vector>
#include <set>
#include <limits> // Include for numeric limits
#include <cstdint> // Include for INT32_MAX

using namespace std;

long long n, m, a, b, c;
vector<pair<long long,long long>> gr[1000000];
long long dist[1000000]; // Changed from 'd' to 'dist' to avoid conflict
bool was[1000000];

long long dijkstra(long long s, long long f){
    for(long long i = 0; i < n; i++){
        dist[i] = (long long) INT32_MAX;
    }
    for(long long i = 0; i < n; i++){
        was[i] = false;
    }
    dist[s] = 0;
    set<pair<long long,long long>> q;
    q.insert({dist[s], s});
    for(long long i = 0; i < n; i++){
        if (q.empty()) {
            break;
        }
        long long v = q.begin()->second;
        q.erase(q.begin());
        was[v] = true;
        for(pair<long long,long long> j : gr[v]){
            long long to = j.first, len = j.second;
            if (was[to]) continue;

            if (dist[v] + len < dist[to]){
                q.erase({dist[to], to});
                dist[to] = dist[v] + len;
                q.insert({dist[to], to});
            }
        }
    }
    return dist[f];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(long long i = 0; i < m; i++){
        cin >> a >> b >> c;
        a--;
        b--;
        gr[a].push_back(make_pair(b, c));
        gr[b].push_back(make_pair(a, c));
    }
    long long d_input;
    cin >> a >> b >> c >> d_input; // Changed variable name from 'd' to 'd_input'
    a--;
    b--;
    c--;
    d_input--;
    long long ans = min(dijkstra(a, b) + dijkstra(b, c) + dijkstra(c, d_input),
                dijkstra(a, c) + dijkstra(c, b) + dijkstra(b, d_input));
    if (ans >= (long long) INT32_MAX) cout << -1;
    else cout << ans;
    return 0;
}
