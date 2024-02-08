
// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     vector<int> boris(5);
//     vector<int> nursik(5);

//     
//     for (int i = 0; i < 5; ++i) {
//         cin >> boris[i];
//     }

//     
//     for (int i = 0; i < 5; ++i) {
//         cin >> nursik[i];
//     }

//     int moves = 0;

//     while (!boris.empty() && !nursik.empty() && moves < 1e6) {
//         int boris_card = boris.back();
//         boris.pop_back();

//         int nursik_card = nursik.back();
//         nursik.pop_back();

//         if ((boris_card == 0 && nursik_card == 9) || (boris_card > nursik_card)) {
//             nursik.insert(nursik.begin(), boris_card);
//             nursik.insert(nursik.begin(), nursik_card);
//         } else {
//             boris.insert(boris.begin(), nursik_card);
//             boris.insert(boris.begin(), boris_card);
//         }

//         moves++;
//     }

//     if (boris.empty()) {
//         cout << "Boris " << moves << endl;
//     } else if (nursik.empty()) {
//         cout << "Nursik " << moves << endl;
//     } else {
//         cout << "blin nichya" << endl;
//     }

//     return 0;
// }

#include <iostream> 
#include <deque> 
using namespace std; 
 
int main(){ 
    deque<int> dq1(5); 
    deque<int> dq2(5); 
    int cnt = 0; 
    for(int i = 0; i < 5; i++){ 
        cin >> dq1[i]; 
    } 
    for(int i = 0; i < 5; i++){ 
        cin >> dq2[i]; 
    } 
    while(cnt < 1000000){ 
        cnt++; 
        int a = dq1.front(); 
        int b = dq2.front(); 
        dq1.pop_front(); 
        dq2.pop_front(); 
        if(a == 0 && b == 9){ 
            dq1.push_back(a); 
            dq1.push_back(b); 
        } 
        else if(a == 9 && b == 0){ 
            dq2.push_back(a); 
            dq2.push_back(b); 
        } 
        else if(a > b){ 
            dq1.push_back(a); 
            dq1.push_back(b); 
        } 
        else{ 
            dq2.push_back(a); 
            dq2.push_back(b); 
        } 
        if(dq1.empty()){ 
            cout << "Nursik " << cnt; 
            return 0; 
        } 
        else if(dq2.empty()){ 
            cout << "Boris " << cnt; 
            return 0; 
        } 
    } 
    cout << "blin nichya"; 
}
