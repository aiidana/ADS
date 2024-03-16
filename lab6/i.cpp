#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string input;
    cin >> input;

    int counts[26] = {0}; 

    
    for (char c : input) {
        counts[c - 'a']++;
    }

    
    string sorted_string;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < counts[i]; ++j) {
            sorted_string.push_back('a' + i);
        }
    }

    cout <<  sorted_string << endl;

    return 0;
}
