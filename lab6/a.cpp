#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool vow(char c){
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string sort_(const string& input_string){
    string vw, cn;
    for(char s : input_string){
        if(isalpha(s)){
            if(vow(s)){
                vw += s;
            } else {
                cn += s;
            }
        }
    }
    sort(vw.begin(), vw.end());
    sort(cn.begin(), cn.end());

    return vw + cn;
}

int main(){
    int n;
    cin >> n;
    string input_string;
    cin >> input_string;
    cout << sort_(input_string);

    return 0;
}
