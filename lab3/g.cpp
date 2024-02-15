#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkCapacity(const vector<int>& children, int f, int capacity) {
    int flightsRequired = 0;
    for (int i = 0; i < children.size(); ++i) {
        flightsRequired += (children[i] + capacity - 1) / capacity; // Округление вверх
    }
    return flightsRequired <= f;
}

int main() {
    int n, f;
    cin >> n >> f;

    vector<int> children(n);
    int totalChildren = 0;
    for (int i = 0; i < n; ++i) {
        cin >> children[i];
        totalChildren += children[i];
    }

    int low = 1, high = totalChildren, minCapacity = totalChildren;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (checkCapacity(children, f, mid)) {
            minCapacity = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << minCapacity << endl;

    return 0;
}