#include <iostream>
#include <vector>
using namespace std;

int cnt = 1; 
int a = 3; 
vector<int> v; 
bool prime(int num){
    int cnt = 0;
    for(int i = 2; i < num; i++){
        if(num % i == 0){
            cnt = 1;
            break;
        }
    }
    if(cnt == 0){
        return true;
    } else {
        return false;
    }
}

void superprime(int a){ 
    for(int i = 2; i <= a / 2; i++){ 
        if(a % i == 0){ 
            return; 
        } 
    } 
    cnt++; 
    if(prime(cnt)){ 
        v.push_back(a); 
    } 
} 

int main(){
    int n;
    cin >> n;
    while(v.size() != n){ 
        superprime(a); 
        a++; 
    } 
    a--; 
    cout << v[n - 1];
    return 0;
}


