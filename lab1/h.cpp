#include <iostream>
using namespace std;
bool prime(int n){
    int cnt=0;
    if(n==1){
        return false;
    }else{
        for(int i=2;i<n;i++){
            if(n%i==0){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    if(prime(n)){
        cout <<"YES";
    }else{
        cout <<"NO";
    }
   
}