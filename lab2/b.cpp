#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string my_func(const string& str, int k) {
    stringstream ss(str);
    vector<string> words;
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    k %= words.size();
    rotate(words.begin(), words.begin() + k, words.end());

    string result;
    for (const string& w : words) {
        result += w + " ";
    }

    if (!result.empty()) {
        result.pop_back();
    }

    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    cin.ignore(); 

    string sentence;
    getline(cin, sentence); 

    string shiftedSentence = my_func(sentence, k);
    cout << shiftedSentence << endl;

    return 0;
}

