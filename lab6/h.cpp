#include <iostream>
#include <vector>

using namespace std;

char balanced(const vector<char>& array, char xx) {
    for (char c : array) {
        if (c > xx) {
            return c;
        }
    }
    return array[0];
}

int main() {
    int n;
    cin >> n;

    vector<char> array(n);
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    char xx;
    cin >> xx;

    char result = balanced(array, xx);
    cout <<  result << endl;

    return 0;
}
