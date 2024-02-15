#include <iostream> 

using namespace std;

int Binary(int blocks[], int trg, int size) {
    int l = 0;
    int r = size - 1;
    int res;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (trg <= blocks[mid]) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
           
        }
    }
    return l;
}


int main () {
    int n, m, sum = 0;
    cin >> n >> m;
    int blocks[n];
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        sum += a;
        blocks[i] = sum;
    }

    while (m--){
        int trg; cin >> trg;
        cout << Binary(blocks, trg, n) + 1<<"\n";
    }

}