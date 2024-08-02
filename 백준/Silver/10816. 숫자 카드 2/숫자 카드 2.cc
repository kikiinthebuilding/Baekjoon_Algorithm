#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, tar;
    cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(), arr.end());

    cin>>n;
    for(int i=0;i<n;i++) {
           cin>>tar;
           auto upper = upper_bound(arr.begin(), arr.end(), tar);
           auto lower = lower_bound(arr.begin(), arr.end(), tar);
           cout<<upper-lower<<" ";
    }
    return 0;
}