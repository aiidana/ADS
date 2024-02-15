#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <cstring>
#define str string
#define ll long long
#define mod 1000000007
#define inf 1e18
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n], prefix[n + 1];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    prefix[0] = 0;
    for (int i = 0; i < n; ++i)
        prefix[i + 1] = arr[i] + prefix[i];
    int left = 0, right = 0, minlength = n;
    while (right <= n)
    {
        if (prefix[right] - prefix[left] >= k)
            minlength = min(minlength, right - left), left++;
        else
            right++;
    }
    cout << minlength;
    return 0;
}