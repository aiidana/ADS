#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> v2; 

    for (int i = 0; i < q; ++i) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if ((l1 <= a[j] && a[j] <= r1) || (l2 <= a[j] && a[j] <= r2)) {
                cnt++;
            }
        }
        v2.push_back(cnt);
    }

    for (int i = 0; i < q; ++i) {
        cout << v2[i] << endl;
    }

    return 0;
}
