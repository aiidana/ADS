#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;


int bfs(int A, int B) {
    queue<pair<int, int>> q; 
    vector<int> operations(2 * B + 1, -1); 
    vector<int> parents(2 * B + 1, -1); 
    
    q.push({A, 0});
    operations[A] = 0;

    while (!q.empty()) {
        int num = q.front().first;
        int ops = q.front().second;
        q.pop();

        if (num == B) {
            break;
        }

        // Try multiplying by 2
        if (num * 2 <= 2 * B && operations[num * 2] == -1) {
            q.push({num * 2, ops + 1});
            operations[num * 2] = ops + 1;
            parents[num * 2] = num;
        }

        // Try decreasing by 1
        if (num - 1 > 0 && operations[num - 1] == -1) {
            q.push({num - 1, ops + 1});
            operations[num - 1] = ops + 1;
            parents[num - 1] = num;
        }
    }

    
    stack<int> sequence;
    int current = B;
    while (current != A) {
        sequence.push(current);
        current = parents[current];
    }
    sequence.push(A);

    
    while (!sequence.empty()) {
        cout << sequence.top() << " ";
        sequence.pop();
    }
    cout << endl;

    return operations[B];
}

int main() {
    int A, B;
    cin >> A >> B;

    int minOps = bfs(A, B);
    cout << minOps << endl;

    return 0;
}
