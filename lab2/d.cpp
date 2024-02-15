#include <iostream>
#include <vector>
#include<map>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0; i<n;i++){
        cin >> v[i];
    }

    map<int,int>mp;
    for(int num:v){
        mp[num]++;
    }
    int max=-999999;
    for(auto it:mp){
        if(it.second>max){
            max=it.second;
        }
    }
    for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
        if (it->second == max) {
            cout << it->first << " ";
        }
    }
    

}