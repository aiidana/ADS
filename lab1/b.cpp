
// #include<iostream>
// #include<vector>
// using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     vector<int>v(n);
//     vector<int>v2;
//     for(int i=0; i<n; i++){
//         cin >> v[i];
//     }
//     v2.push_back(-1);

//     for(int i=0; i<n; i++){
        
//         if(v[i]<v[i+1]){
//             v2.push_back(v[i]);
//         }else{
//             v2.push_back(-1);
//         }
//     }
//     for(int i=0; i<n; i++){
//         cout<<v2[i]<<' ';
//     }

// }

#include <iostream> 
#include <deque> 
using namespace std; 
 
int main(){ 
    int n; 
    cin >> n; 
    deque<int> dq; 
    deque<int> ans; 
    for(int i = 0; i < n; i++){ 
        int x; 
        cin >> x; 
        dq.push_back(x); 
    } 
    ans.push_back(-1); 
    for(int i = 1; i < dq.size(); i++){ 
        int j = i - 1; 
        while(j >= 0){ 
            if(dq[j] <= dq[i]){ 
                ans.push_back(dq[j]); 
                break; 
            } 
            if(j == 0){ 
                ans.push_back(-1); 
            } 
            j--; 
        } 
    } 
    for(int i = 0; i < ans.size(); i++){ 
        cout << ans[i] << " "; 
    } 
}

