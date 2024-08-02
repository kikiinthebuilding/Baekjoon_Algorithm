#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin>>n>>m;
    int x=n+m; int arr[x];
    for(int i=0;i<x;i++) cin>>arr[i];
    sort(arr, arr+x);
    for(int i=0;i<x;i++) printf("%d ", arr[i]);
    return 0;
}