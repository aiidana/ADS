#include <iostream>
#include <queue>
using namespace std;
bool prime(int num){
    int cnt=0;
    for(int i=2; i<num; i++){
        if(num%i==0){
            cnt=1;
            break;
        }
    }
    if(cnt==0){
        return true;
    }else{
        return false;
    }
    
}
int nth(int n){
    int num=1,cnt=0;
    queue <int>q;
    while(true){
        num++;
        if(prime(num)){
            q.push(num);
            cnt++;
        }
        if(cnt==n){
            return q.back();
            break;
        }
    }
}
int main(){
    int n;
    cin >> n;
    cout << nth(n);
    return 0;

}