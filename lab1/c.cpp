#include <iostream>
using namespace std;
string test(string s){
    string res;
    for(char ch:s){
        if(ch == '#' && !res.empty()){
            res.pop_back();
        }else if (ch != '#') {
            res.push_back(ch);
        }
    }
    return res;
}
int main(){
    string s1,s2;
    cin >> s1>> s2;
    string ss1=test(s1);
    string ss2=test(s2);
    if(ss1==ss2){
        cout <<"Yes";
    }else{
        cout << "No";
    }
}





