#include <iostream> 
#include <deque> 
using namespace std; 
 
int main(){ 
    deque<int> deq; 
    char s; 
    while(s != '!'){ 
        cin >> s; 
        if(s == '+'){ 
            int x; 
            cin >> x; 
            deq.push_back(x); 
        } 
        if(s == '-'){ 
            int x; 
            cin >> x; 
            deq.push_front(x); 
        } 
        if(s == '*'){ 
            if(!deq.empty()){ 
                cout << deq.front() + deq.back() << endl; 
                deq.pop_front(); 
                if(!deq.empty()){ 
                    deq.pop_back(); 
                } 
            } 
            else{ 
                cout << "error" << endl; 
            } 
        } 
    } 
}
