#include <iostream>
#include <vector>
using namespace std;
int near(vector<int>v,int k){
    int ind=-1, min=9999999;
    
    for(int i=0; i<v.size(); i++){
        int d;
        d=abs(v[i]-k);
        if(d<min){
            min=d;
            ind=i;
        }
    }    
    return ind;

}
int main(){
    int n;
    cin >>n;
    vector<int>v(n);
    for(int i=0; i<n;i++){
        cin >> v[i];
    }
    int k;
    cin >> k;
    cout << near(v,k);

}
