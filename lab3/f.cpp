#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>v1(n);
    for(int i=0; i<n; i++){
        cin >> v1[i];
    }
    int p;
    cin >>p;
    
    vector<pair<int,int>>v2;
    for(int i=0; i<p; i++){
        int x;
        cin >>x;
        int cnt=0,sum=0;
        for(int j=0;j<n;j++){
            if(x>=v1[j]){
                cnt++;
                sum+=v1[j];

            }
        }
        v2.push_back(make_pair(cnt,sum));
        
        
    }
    for(auto it:v2){
        cout << it.first <<" "<< it.second<<endl;
    }
}