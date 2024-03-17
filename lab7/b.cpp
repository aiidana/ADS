#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n;

    multiset<int> mt;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mt.insert(v[i]);
    }

    cin >> m;
    vector<int> v1(m);
    for (int i = 0; i < m; i++) {
        cin >> v1[i];
        mt.insert(v1[i]);
    }

    for (auto it = mt.begin(); it != mt.end(); it++) {
        cout << *it << ' ';
    }

    return 0;
}
