#include<iostream>
#include<string>
using namespace std;

int countOccurrences(const std::string& s, const std::string& t) {
    int count = 0;
    size_t pos = 0;
    while ((pos = t.find(s, pos)) != std::string::npos) {
        count++;
        pos += s.length(); 
    }
    return count;
}
bool check(string s, string t,int k){
    if(countOccurrences(s,t)>=k){
        return true;
    }else return false;


}
int main(){
    string s;
    int k;
    cin >> s>> k;
    string t;
    cin >> t;
    if(check(s,t,k)){
        cout <<"YES";
    }else{
        cout<<"NO";
    }

}