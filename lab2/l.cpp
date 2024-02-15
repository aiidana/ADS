#include <iostream>
#include <vector>
using namespace std;

pair<int, pair<int, int>> max_subarray_sum(vector<int>& arr) {
    int max_ending_here = arr[0];
    int max_so_far = arr[0];
    int start = 0;
    int end = 0;
    int temp_start = 0;

    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > max_ending_here + arr[i]) {
            max_ending_here = arr[i];
            temp_start = i;
        } else {
            max_ending_here += arr[i];
        }

        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
            start = temp_start;
            end = i;
        }
    }

    return {max_so_far, {start, end}};
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    
    auto result = max_subarray_sum(arr);
    cout << result.first << endl; 

    return 0;
}
