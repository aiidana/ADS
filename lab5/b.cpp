#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    priority_queue<int> max_heap;

    for (int i = 0; i < N; ++i) {
        int weight;
        cin >> weight;
        max_heap.push(weight);
    }

    while (max_heap.size() > 1) {
        int heaviest1 = max_heap.top();
        max_heap.pop();
        int heaviest2 = max_heap.top();
        max_heap.pop();

        if (heaviest1 != heaviest2) {
            max_heap.push(heaviest1 - heaviest2);
        }
    }

    if (max_heap.empty()) {
        cout << "0\n";
    } else {
        cout << max_heap.top() << endl;
    }

    return 0;
}
