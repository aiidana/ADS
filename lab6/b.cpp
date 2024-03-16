// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<int> v1(n);
//     vector<int> v2(m);
//     vector<int> vv;
    
//     for(int i = 0; i < n; i++) {
//         cin >> v1[i];
//     }
    
//     for(int i = 0; i < m; i++) {
//         cin >> v2[i];
//     }
    
//     vector<bool> used(m, false); 
    
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             if(v1[i] == v2[j] && !used[j]) {
//                 vv.push_back(v2[j]);
//                 used[j] = true; 
//                 break; 
//             }
//         }
//     }
    
//     for(int i = 0; i < vv.size(); i++) {
//         cout << vv[i] << " ";
//     }

//     return 0;
// }
// #include <iostream>
// #include <vector>
// #include <unordered_map>

// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<int> v1(n);
//     vector<int> v2(m);
//     unordered_map<int, int> freq;

//     for(int i = 0; i < n; i++) {
//         cin >> v1[i];
//     }

//     for(int i = 0; i < m; i++) {
//         cin >> v2[i];
//         freq[v2[i]]++; 
//     }

//     vector<int> vv;

//     for(int i = 0; i < n; i++) {
//         if(freq.find(v1[i]) != freq.end() && freq[v1[i]] > 0) {
//             vv.push_back(v1[i]);
//             freq[v1[i]]--; 
//         }
//     }

//     for(int i = 0; i < vv.size(); i++) {
//         cout << vv[i] << " ";
//     }

//     return 0;
// }
#include <cmath>
#include <iostream>
using namespace std;
  
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i= (low - 1);
  
    for (int j = low; j <= high - 1; j++) {

        if (arr[j] < pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
  
void quickSort(int arr[], int low, int high)
{
    if (low < high) {

        int pi = partition(arr, low, high);
  

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
  
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
  

int main() {
    int n; cin >> n;
    int m; cin >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    quickSort(a, 0, n - 1);
    quickSort(b, 0, m - 1);
    int i = 0;
    int j = 0;
    while(i != n && j != m) {
        if(a[i] == b[j]) {
            cout << b[j] << " ";
            i++;
            j++;
        }
        else if(a[i] <  b[j]) {
            i++;
        }
        else if(a[i] > b[j]) {
            j++;
        }
    }

    return 0;
}