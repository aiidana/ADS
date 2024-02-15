#include<iostream>
using namespace std;
bool search(int a[],int n,int x){
    for(int i=0; i<n; i++){
        if(a[i]==x){
            return true;
            break;
        }
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n;i++){
        cin >> a[i];
    }
    int x;
    cin >> x;
    if(search(a,n,x)){
        cout <<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

}