
// #include<iostream>
// using namespace std;

// int main() {
//     int t;
//     cin >> t;
//     int a[t];
//     for (int i = 0; i < t; i++) {
//         cin >> a[i];
//     }
//     int n, m;
//     cin >> n >> m;
//     int b[n][m];
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> b[i][j];
//         }
//     }
//     for (int i = 0; i < t; i++) {
//         bool found = false;
//         for (int j = 0; j < n; j++) {
//             if (j % 2 == 0) { 
//                 for (int k = 0; k < m; k++) {
//                     if (b[j][k] == a[i]) {
//                         cout << j << " " << k << endl;
//                         found = true;
//                         break;
//                     }
//                 }
//             } else { // Odd row
//                 for (int k = m - 1; k >= 0; k--) {
//                     if (b[j][k] == a[i]) {
//                         cout << j << " " << k << endl;
//                         found = true;
//                         break;
//                     }
//                 }
//             }
//             if (found) break;
//         }
//         if (!found) cout << -1 << endl;
//     }
//     return 0;
// }
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    unordered_map<int, pair<int, int>> coordinates; // Store coordinates of each element
    vector<int> elements(t);
    for (int i = 0; i < t; i++) {
        cin >> elements[i];
    }

    int n, m;
    cin >> n >> m;

    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
            coordinates[b[i][j]] = {i, j}; // Store coordinates of each element
        }
    }

    for (int i = 0; i < t; i++) {
        if (coordinates.find(elements[i]) != coordinates.end()) {
            cout << coordinates[elements[i]].first << " " << coordinates[elements[i]].second << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
